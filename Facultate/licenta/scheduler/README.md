# Python Task Scheduler

A simple task scheduler with a text-based interface that can run as a system daemon.

## Features

- Schedule one-time or recurring tasks
- Support for cron-like scheduling
- Desktop notifications for task completion/failure
- Task persistence across reboots
- Logging of task execution
- Interactive menu interface

## Installation

1. Create and activate a virtual environment:
```bash
python -m venv venv
source venv/bin/activate
```

2. Install dependencies:
```bash
pip install -r requirements.txt
```

3. Install the systemd service:
```bash
sudo cp scheduler.service /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl enable scheduler
sudo systemctl start scheduler
```

## Usage

### Running the Scheduler

1. Start the scheduler in interactive mode:
```bash
python -m src.main
```

2. The scheduler will automatically start on system boot when installed as a service.

### Managing Tasks

The scheduler provides an interactive menu with the following options:

1. Add new task
   - Enter task ID
   - Enter command to execute
   - Enter task description (optional)
   - Choose task type (one-time or recurring)
   - For recurring tasks, enter cron schedule
   - For one-time tasks, enter date and time

2. List all tasks
   - View all scheduled tasks with their details

3. Remove task
   - Select and remove a task by ID

4. Exit
   - Safely exit the scheduler

### Cron Schedule Format

The scheduler uses standard cron format:
```
minute hour day month weekday
```

Examples:
- `*/15 * * * *` - Every 15 minutes
- `0 * * * *` - Every hour
- `0 0 * * *` - Every day at midnight
- `0 0 * * 1` - Every Monday at midnight

## Logs

Logs are stored in the `logs` directory:
- `scheduler.log` - Main scheduler log file

## Task Storage

Tasks are stored in `data/tasks.json` and persist across reboots. 