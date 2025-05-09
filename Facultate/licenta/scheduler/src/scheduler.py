import json
import logging
from pathlib import Path
from datetime import datetime
from apscheduler.schedulers.background import BackgroundScheduler
from apscheduler.jobstores.memory import MemoryJobStore
from apscheduler.executors.pool import ThreadPoolExecutor
from apscheduler.triggers.cron import CronTrigger
from apscheduler.triggers.date import DateTrigger
from apscheduler.triggers.interval import IntervalTrigger
from plyer import notification

class TaskScheduler:
    def __init__(self, data_dir: str = "data", log_dir: str = "logs"):
        self.data_dir = Path(data_dir)
        self.log_dir = Path(log_dir)
        self.tasks_file = self.data_dir / "tasks.json"
        
        # Ensure directories exist
        self.data_dir.mkdir(exist_ok=True)
        self.log_dir.mkdir(exist_ok=True)
        
        # Setup logging
        logging.basicConfig(
            filename=self.log_dir / "scheduler.log",
            level=logging.INFO,
            format='%(asctime)s - %(levelname)s - %(message)s'
        )
        
        # Initialize scheduler
        jobstores = {
            'default': MemoryJobStore()
        }
        executors = {
            'default': ThreadPoolExecutor(20)
        }
        job_defaults = {
            'coalesce': False,
            'max_instances': 1
        }
        
        self.scheduler = BackgroundScheduler(
            jobstores=jobstores,
            executors=executors,
            job_defaults=job_defaults
        )
        
        # Load existing tasks
        self.load_tasks()
        
    def load_tasks(self):
        """Load tasks from JSON file and schedule them"""
        if not self.tasks_file.exists():
            return
            
        try:
            with open(self.tasks_file, 'r') as f:
                tasks = json.load(f)
                
            for task in tasks:
                self.add_task(
                    task_id=task['id'],
                    command=task['command'],
                    schedule=task['schedule'],
                    is_cron=task.get('is_cron', True),  # Default to True for backward compatibility
                    description=task.get('description', '')
                )
        except Exception as e:
            logging.error(f"Error loading tasks: {e}")
            
    def save_tasks(self):
        """Save current tasks to JSON file"""
        tasks = []
        for job in self.scheduler.get_jobs():
            if isinstance(job.trigger, CronTrigger):
                schedule = job.trigger.fields_repr
                is_cron = True
            elif isinstance(job.trigger, IntervalTrigger):
                schedule = f"interval:{job.trigger.interval.total_seconds()}"
                is_cron = False
            else:
                schedule = str(job.trigger)
                is_cron = False
                
            task = {
                'id': job.id,
                'command': job.args[0],
                'schedule': schedule,
                'is_cron': is_cron,
                'description': job.args[1] if len(job.args) > 1 else ''
            }
            tasks.append(task)
            
        try:
            with open(self.tasks_file, 'w') as f:
                json.dump(tasks, f, indent=4)
        except Exception as e:
            logging.error(f"Error saving tasks: {e}")
            
    def add_task(self, task_id: str, command: str, schedule: str, is_cron: bool = True, description: str = ""):
        """Add a new task to the scheduler"""
        try:
            if schedule.startswith('interval:'):
                # Handle interval-based scheduling
                seconds = int(float(schedule.split(':')[1]))  # Handle float values
                trigger = IntervalTrigger(seconds=seconds)
            elif is_cron:
                trigger = CronTrigger.from_crontab(schedule)
            else:
                trigger = DateTrigger(run_date=datetime.fromisoformat(schedule))
                
            self.scheduler.add_job(
                self._execute_task,
                trigger=trigger,
                id=task_id,
                args=[command, description],
                replace_existing=True
            )
            
            self.save_tasks()
            logging.info(f"Added task {task_id}: {command}")
            return True
        except Exception as e:
            logging.error(f"Error adding task {task_id}: {e}")
            return False
            
    def remove_task(self, task_id: str):
        """Remove a task from the scheduler"""
        try:
            self.scheduler.remove_job(task_id)
            self.save_tasks()
            logging.info(f"Removed task {task_id}")
            return True
        except Exception as e:
            logging.error(f"Error removing task {task_id}: {e}")
            return False
            
    def list_tasks(self):
        """Get list of all scheduled tasks"""
        tasks = []
        for job in self.scheduler.get_jobs():
            task = {
                'id': job.id,
                'command': job.args[0],
                'next_run': job.next_run_time,
                'schedule': str(job.trigger),
                'description': job.args[1] if len(job.args) > 1 else ''
            }
            tasks.append(task)
        return tasks
        
    def _execute_task(self, command: str, description: str):
        """Execute a scheduled task"""
        try:
            import subprocess
            result = subprocess.run(command, shell=True, capture_output=True, text=True)
            
            if result.returncode == 0:
                logging.info(f"Task executed successfully: {command}")
                notification.notify(
                    title='Task Completed',
                    message=f'Task completed successfully: {description or command}',
                    timeout=10
                )
            else:
                logging.error(f"Task failed: {command}\nError: {result.stderr}")
                notification.notify(
                    title='Task Failed',
                    message=f'Task failed: {description or command}\nError: {result.stderr}',
                    timeout=10
                )
        except Exception as e:
            logging.error(f"Error executing task {command}: {e}")
            notification.notify(
                title='Task Error',
                message=f'Error executing task: {description or command}\nError: {str(e)}',
                timeout=10
            )
            
    def start(self):
        """Start the scheduler"""
        if not self.scheduler.running:
            self.scheduler.start()
            logging.info("Scheduler started")
            
    def shutdown(self):
        """Shutdown the scheduler"""
        if self.scheduler.running:
            self.scheduler.shutdown()
            logging.info("Scheduler shutdown") 