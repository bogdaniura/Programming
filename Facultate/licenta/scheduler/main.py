from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from datetime import datetime
from apscheduler.schedulers.background import BackgroundScheduler
from apscheduler.triggers.cron import CronTrigger
import subprocess
import uuid
import json
import os
from typing import Optional, Dict, List
from threading import Lock

# Inițializează aplicația FastAPI
app = FastAPI(title="JSON JobScheduler")

# Calea către fișierul JSON
JSON_FILE = "jobs.json"

# Lock pentru operațiuni atomice cu fișierul
file_lock = Lock()

# Structura inițială a fișierului JSON
INITIAL_JSON = {
    "jobs": {},
    "runs": []
}

# Încarcă datele din fișier
def load_data() -> Dict:
    if not os.path.exists(JSON_FILE):
        with open(JSON_FILE, "w") as f:
            json.dump(INITIAL_JSON, f)
    
    with open(JSON_FILE, "r") as f:
        return json.load(f)

# Salvează datele în fișier
def save_data(data: Dict):
    with open(JSON_FILE, "w") as f:
        json.dump(data, f, default=str)

# Inițializează scheduler-ul
scheduler = BackgroundScheduler()
scheduler.start()

# Model Pydantic pentru cererea de creare a unui job
class JobRequest(BaseModel):
    schedule: str  # ex: "* * * * *"
    command: str   # ex: "python myscript.py"
    timeout: int = 30  # timeout în secunde

# Model pentru răspuns
class JobResponse(BaseModel):
    id: str
    schedule: str
    command: str
    status: str
    last_run: Optional[datetime] = None

# Încarcă job-urile existente la pornire
@app.on_event("startup")
def load_existing_jobs():
    data = load_data()
    for job_id, job in data["jobs"].items():
        schedule_job(job_id, job["schedule"], job["command"])

def schedule_job(job_id: str, schedule: str, command: str):
    def execute_job():
        try:
            print(f"Executing job {job_id}: {command}")
            result = subprocess.run(
                command.split(), 
                timeout=30,
                capture_output=True,
                text=True
            )
            
            status = "success" if result.returncode == 0 else "failed"
            output = f"{result.stdout}\n{result.stderr}".strip()
            
        except subprocess.TimeoutExpired as e:
            status = "timeout"
            output = str(e)
        except Exception as e:
            status = f"error: {str(e)}"
            output = str(e)
        
        # Actualizează istoricul
        with file_lock:
            data = load_data()
            data["runs"].append({
                "job_id": job_id,
                "status": status,
                "output": output,
                "timestamp": datetime.now().isoformat()
            })
            save_data(data)

    # Adaugă job-ul în scheduler
    scheduler.add_job(
        execute_job,
        trigger=CronTrigger.from_crontab(schedule),
        id=job_id
    )

# Endpoint pentru creare job
@app.post("/jobs", response_model=JobResponse)
def create_job(job_request: JobRequest):
    job_id = str(uuid.uuid4())
    
    with file_lock:
        data = load_data()
        data["jobs"][job_id] = {
            "schedule": job_request.schedule,
            "command": job_request.command,
            "status": "scheduled",
            "last_run": None
        }
        save_data(data)
    
    schedule_job(job_id, job_request.schedule, job_request.command)
    
    return {
        "id": job_id,
        **data["jobs"][job_id]
    }

# Endpoint pentru listare job-uri
@app.get("/jobs", response_model=Dict[str, JobResponse])
def list_jobs():
    data = load_data()
    # Construiește răspunsul cu id-ul inclus
    formatted_jobs = {}
    for job_id, job_data in data["jobs"].items():
        formatted_jobs[job_id] = {
            "id": job_id,
            "schedule": job_data["schedule"],
            "command": job_data["command"],
            "status": job_data.get("status", "scheduled"),
            "last_run": datetime.fromisoformat(job_data["last_run"]) if job_data["last_run"] else None
        }
    return formatted_jobs

# Endpoint pentru ștergere job
@app.delete("/jobs/{job_id}")
def delete_job(job_id: str):
    with file_lock:
        data = load_data()
        if job_id not in data["jobs"]:
            raise HTTPException(status_code=404, detail="Job not found")
        
        # Șterge din scheduler
        scheduler.remove_job(job_id)
        
        # Șterge din JSON
        del data["jobs"][job_id]
        save_data(data)
        return {"status": "deleted"}