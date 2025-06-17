# Advanced Python Task Scheduler

A robust, feature-rich task scheduler built in Python with an interactive text-based interface. This scheduler provides comprehensive task management capabilities with support for multiple scheduling types, desktop notifications, persistent storage, and detailed logging.

## 🚀 Features

### Core Functionality
- **Multiple Scheduling Types**: Support for cron expressions, interval-based scheduling, and one-time tasks
- **Interactive Menu Interface**: Rich, user-friendly command-line interface with navigation
- **Task Persistence**: Automatic saving and loading of tasks across system reboots
- **Desktop Notifications**: Optional desktop notifications for task completion and failures
- **Comprehensive Logging**: Detailed execution logs with timestamps and error tracking
- **Task Management**: Add, edit, list, and remove tasks with full CRUD operations

### Advanced Capabilities
- **Background Processing**: Tasks run in background threads without blocking the interface
- **Error Handling**: Robust error handling with detailed error reporting
- **Resource Management**: Configurable thread pool for concurrent task execution
- **Task Validation**: Input validation and error checking for all task parameters
- **Flexible Scheduling**: Support for complex cron expressions and custom intervals

## 📋 Requirements

- Python 3.7+
- Linux/Unix system (for daemon functionality)
- Required Python packages (see `requirements.txt`)

## 🛠️ Installation

1. **Clone or download the project**:
   ```bash
   cd /path/to/scheduler
   ```

2. **Create and activate virtual environment**:
   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows: venv\Scripts\activate
   ```

3. **Install dependencies**:
   ```bash
   pip install -r requirements.txt
   ```

4. **Set execute permissions** (Linux/Unix):
   ```bash
   chmod +x src/main.py
   ```

## 🚀 Usage

### Starting the Scheduler

Run the scheduler in interactive mode:
```bash
python -m src.main
```

The scheduler will start and display the main menu with task management options.

### Main Menu Options

1. **New Task** - Add a new scheduled task
2. **List Tasks** - View all scheduled tasks with details
3. **Edit Task** - Modify existing task parameters
4. **Delete Task** - Remove a task from the scheduler
5. **Exit** - Safely shutdown the scheduler

### Adding Tasks

When adding a new task, you'll be prompted for:

- **Task ID**: Unique identifier for the task
- **Command**: Shell command or script to execute
- **Description**: Optional description for the task
- **Task Type**: One-time or recurring
- **Schedule**: 
  - For one-time tasks: Date and time (YYYY-MM-DD HH:MM:SS)
  - For recurring tasks: Cron expression or interval in seconds
- **Notifications**: Enable/disable desktop notifications

### Scheduling Types

#### Cron Expressions
Standard cron format: `minute hour day month weekday`

Examples:
- `*/15 * * * *` - Every 15 minutes
- `0 3 * * *` - Every day at 3:00 AM
- `0 0 * * 1` - Every Monday at midnight
- `30 14 * * 5` - Every Friday at 2:30 PM

#### Interval Scheduling
Specify intervals in seconds:
- `60` - Every minute
- `3600` - Every hour
- `86400` - Every day

#### One-time Tasks
Specify exact date and time:
- `2024-01-15 14:30:00` - January 15, 2024 at 2:30 PM

## 📁 Project Structure

```
scheduler/
├── src/
│   ├── main.py          # Main entry point
│   ├── scheduler.py     # Core scheduler logic
│   └── menu.py          # Interactive menu interface
├── data/
│   └── tasks.json       # Persistent task storage
├── logs/
│   └── scheduler.log    # Execution logs
├── tests/
│   └── scripts/         # Test scripts for validation
├── requirements.txt     # Python dependencies
└── README.md           # This file
```

## 🔧 Configuration

### Task Storage
Tasks are automatically saved to `data/tasks.json` and persist across system restarts.

### Logging
Detailed logs are written to `logs/scheduler.log` including:
- Task execution status
- Error messages and stack traces
- Scheduler startup/shutdown events
- Task addition/removal events

### Notifications
Desktop notifications can be enabled per task and show:
- Task completion status
- Error messages for failed tasks
- Task execution timestamps

## 🧪 Testing

The project includes comprehensive test scripts in `tests/scripts/` for validating scheduler functionality:

- **Resource-intensive tests**: CPU, memory, disk I/O, and network operations
- **Basic functionality tests**: Simple tasks and error handling
- **Long-running tasks**: Extended duration task validation

See `tests/scripts/README.md` for detailed testing information.

## 🔍 Monitoring

### Task Status
- View all scheduled tasks with their next run times
- Monitor task execution history through logs
- Check task success/failure rates

### System Resources
- Monitor CPU and memory usage during task execution
- Track disk I/O for file operations
- Monitor network activity for web requests

## 🛡️ Error Handling

The scheduler provides robust error handling:
- Invalid cron expressions are rejected with helpful error messages
- Failed task executions are logged with detailed error information
- System errors are caught and logged without crashing the scheduler
- Task validation prevents invalid configurations

## 🔄 Task Persistence

Tasks are automatically:
- Saved when added, edited, or removed
- Loaded when the scheduler starts
- Preserved across system reboots
- Validated for integrity on startup

## 📊 Dependencies

- **APScheduler**: Advanced Python Scheduler for task scheduling
- **plyer**: Cross-platform desktop notifications
- **rich**: Enhanced terminal output and formatting
- **python-daemon**: Daemon process support
- **lockfile**: File locking for process safety

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request

## 📝 License

This project is part of a university thesis/license project.

## 🆘 Troubleshooting

### Common Issues

1. **Task not executing**: Check the cron expression format and ensure the scheduler is running
2. **Permission errors**: Ensure scripts have execute permissions
3. **Notification issues**: Verify desktop notification support on your system
4. **Log file access**: Check write permissions for the logs directory

### Debug Mode
Enable detailed logging by modifying the logging level in `src/main.py`:
```python
logging.basicConfig(level=logging.DEBUG)
```

## 🔮 Future Enhancements

- Web-based interface
- REST API for remote management
- Task dependencies and workflows
- Resource usage monitoring
- Email notifications
- Task templates and presets 