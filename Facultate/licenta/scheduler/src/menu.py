import os
from datetime import datetime
from apscheduler.triggers.interval import IntervalTrigger
from apscheduler.triggers.date import DateTrigger
from .scheduler import TaskScheduler

class SchedulerMenu:
    def __init__(self):
        self.scheduler = TaskScheduler(notifications_enabled=False)
        self.scheduler.start()
        
    def clear_screen(self):
        os.system('clear' if os.name == 'posix' else 'cls')
        
    def display_menu(self):
        self.clear_screen()
        print("Task Scheduler")
        print("1. New task")
        print("2. List tasks")
        print("3. Edit task")
        print("4. Delete task")
        print("5. Exit")
        print("\nb: back  m: menu\n")
        
    def get_valid_task_id(self, tasks, operation="edit"):
        """Get a valid task ID from user input with retry logic"""
        task_ids = [t['id'] for t in tasks]
        
        while True:
            task_id = input(f"Task ID to {operation} (b: back): ")
            if task_id.lower() == 'b':
                return None, None
            if task_id.lower() == 'm':
                return 'main', None
                
            task = next((t for t in tasks if t['id'] == task_id), None)
            if task:
                return task_id, task
            else:
                print("Task not found")
                self.clear_screen()
                print(f"{operation.title()} Task")
                self.display_task_table(tasks)
        
    def display_task_table(self, tasks, show_notifications=True):
        """Display a table of tasks with common columns"""
        if not tasks:
            print("No tasks")
            return
            
        print("\nTasks:")
        print("-" * 100)
        print(f"{'ID':<10} {'Command':<30} {'Schedule':<25} {'Description':<25} {'Notif':<5}")
        print("-" * 100)
        
        for task in tasks:
            notif_status = "On" if task['notifications_enabled'] else "Off"
            print(f"{task['id']:<10} {task['command']:<30} {str(task['schedule']):<25} {task['description']:<25} {notif_status:<5}")
        print("-" * 100)
        
    def get_valid_input(self, prompt, valid_options=None, allow_empty=False, is_numeric=False, min_value=None, max_value=None):
        """Get valid input from user with retry logic"""
        while True:
            value = input(prompt)
            
            # Check for navigation commands
            if value.lower() == 'b':
                return None
            if value.lower() == 'm':
                return 'main'
                
            # Check if empty is allowed
            if not value and not allow_empty:
                print("Input cannot be empty")
                continue
                
            # Check if numeric
            if is_numeric:
                try:
                    num = int(value)
                    if min_value is not None and num < min_value:
                        print(f"Value must be at least {min_value}")
                        continue
                    if max_value is not None and num > max_value:
                        print(f"Value must be at most {max_value}")
                        continue
                    return str(num)
                except ValueError:
                    print("Please enter a valid number")
                    continue
                    
            # Check if in valid options
            if valid_options and value not in valid_options:
                print(f"Please enter one of: {', '.join(valid_options)}")
                continue
                
            return value
            
    def add_task(self):
        self.clear_screen()
        print("New Task")
        
        while True:
            task_id = self.get_valid_input("Task ID (b: back): ")
            if task_id is None:
                return
            if task_id == 'main':
                return 'main'
                
            # Check if task ID already exists
            existing_tasks = self.scheduler.list_tasks()
            if any(t['id'] == task_id for t in existing_tasks):
                print("ID exists")
                continue
            break
            
        command = self.get_valid_input("Command (b: back): ")
        if command is None:
            return
        if command == 'main':
            return 'main'
            
        description = self.get_valid_input("Description (b: back): ")
        if description is None:
            return
        if description == 'main':
            return 'main'
        
        print("\nTask type:")
        print("1. One-time")
        print("2. Recurring")
        task_type = self.get_valid_input("Choice: ", valid_options=["1", "2"])
        if task_type is None:
            return
        if task_type == 'main':
            return 'main'
        
        if task_type == "1":
            while True:
                try:
                    date_str = self.get_valid_input("Date (YYYY-MM-DD HH:MM:SS) (b: back): ")
                    if date_str is None:
                        return
                    if date_str == 'main':
                        return 'main'
                    schedule = datetime.strptime(date_str, "%Y-%m-%d %H:%M:%S").isoformat()
                    break
                except ValueError:
                    print("Invalid date format. Use YYYY-MM-DD HH:MM:SS")
                    continue
            is_cron = False
        else:
            print("\nSchedule type:")
            print("1. Cron")
            print("2. Interval")
            schedule_type = self.get_valid_input("Choice: ", valid_options=["1", "2"])
            if schedule_type is None:
                return
            if schedule_type == 'main':
                return 'main'
            
            if schedule_type == "2":
                while True:
                    try:
                        seconds = int(self.get_valid_input("Interval (seconds) (b: back): ", is_numeric=True, min_value=1))
                        if seconds is None:
                            return
                        if seconds == 'main':
                            return 'main'
                        schedule = f"interval:{seconds}"
                        break
                    except ValueError:
                        print("Invalid interval")
                        continue
                is_cron = True
            else:
                while True:
                    print("\nCron format: minute hour day month weekday")
                    print("Examples:")
                    print("*/15 * * * *  (every 15 min)")
                    print("0 3 * * *     (3 AM daily)")
                    print("0 0 * * 1     (midnight Mon)")
                    schedule = self.get_valid_input("Schedule (b: back): ")
                    if schedule is None:
                        return
                    if schedule == 'main':
                        return 'main'
                    try:
                        from apscheduler.triggers.cron import CronTrigger
                        CronTrigger.from_crontab(schedule)
                        break
                    except ValueError:
                        print("Invalid cron format")
                        continue
                is_cron = True
        
        notifications_enabled = self.get_valid_input("\nEnable notifications? (y/n): ", valid_options=["y", "n"]).lower() == 'y'
            
        if self.scheduler.add_task(task_id, command, schedule, is_cron, description, notifications_enabled):
            print("Task added")
        else:
            print("Failed to add task")
            
        input("\nEnter to continue...")
        
    def list_tasks(self):
        self.clear_screen()
        print("Tasks")
        
        tasks = self.scheduler.list_tasks()
        self.display_task_table(tasks)
            
        input("\nEnter to continue...")
        
    def remove_task(self):
        self.clear_screen()
        print("Delete Task")
        
        tasks = self.scheduler.list_tasks()
        if not tasks:
            print("No tasks")
            input("\nEnter to continue...")
            return
            
        self.display_task_table(tasks)
        
        task_id, task = self.get_valid_task_id(tasks, "delete")
        if task_id is None:
            return
        if task_id == 'main':
            return 'main'
            
        if input(f"Delete task {task_id}? (y/n): ").lower() == 'y':
            if self.scheduler.remove_task(task_id):
                print("Task deleted")
            else:
                print("Failed to delete")
                
        input("\nEnter to continue...")
        
    def edit_task(self):
        self.clear_screen()
        print("Edit Task")
        
        tasks = self.scheduler.list_tasks()
        if not tasks:
            print("No tasks")
            input("\nEnter to continue...")
            return
            
        self.display_task_table(tasks)
        
        task_id, task_to_edit = self.get_valid_task_id(tasks, "edit")
        if task_id is None:
            return
        if task_id == 'main':
            return 'main'
            
        while True:
            print("\nEdit:")
            print("1. Command")
            print("2. Schedule")
            print("3. Description")
            print("4. Notifications")
            print("5. Back")
            
            choice = self.get_valid_input("\nChoice: ", valid_options=["1", "2", "3", "4", "5"])
            if choice is None:
                continue
            if choice == 'main':
                return 'main'
            
            if choice == "5":
                break
                
            # Get fresh task data before each edit
            current_task = next((t for t in self.scheduler.list_tasks() if t['id'] == task_id), None)
            if not current_task:
                print("Task not found")
                break
                
            if choice == "1":
                new_command = self.get_valid_input("New command (b: back): ")
                if new_command is None:
                    continue
                if new_command == 'main':
                    return 'main'
                    
                # Update task without removing it
                self.scheduler.scheduler.modify_job(
                    job_id=task_id,
                    args=[new_command, current_task['description'], current_task['notifications_enabled']]
                )
                self.scheduler.save_tasks()
                print("Command updated")
                    
            elif choice == "2":
                print("\nSchedule type:")
                print("1. Cron")
                print("2. Interval")
                print("3. One-time")
                schedule_type = self.get_valid_input("Choice: ", valid_options=["1", "2", "3"])
                if schedule_type is None:
                    continue
                if schedule_type == 'main':
                    return 'main'
                
                if schedule_type == "2":
                    while True:
                        try:
                            seconds = int(self.get_valid_input("Interval (seconds) (b: back): ", is_numeric=True, min_value=1))
                            if seconds is None:
                                break
                            if seconds == 'main':
                                return 'main'
                            trigger = IntervalTrigger(seconds=seconds)
                            break
                        except ValueError:
                            print("Invalid interval")
                            continue
                elif schedule_type == "3":
                    while True:
                        try:
                            date_str = self.get_valid_input("Date (YYYY-MM-DD HH:MM:SS) (b: back): ")
                            if date_str is None:
                                break
                            if date_str == 'main':
                                return 'main'
                            run_date = datetime.strptime(date_str, "%Y-%m-%d %H:%M:%S")
                            trigger = DateTrigger(run_date=run_date)
                            break
                        except ValueError:
                            print("Invalid date format. Use YYYY-MM-DD HH:MM:SS")
                            continue
                else:
                    while True:
                        print("\nCron format: minute hour day month weekday")
                        print("Examples:")
                        print("*/15 * * * *  (every 15 min)")
                        print("0 3 * * *     (3 AM daily)")
                        print("0 0 * * 1     (midnight Mon)")
                        cron_schedule = self.get_valid_input("Schedule (b: back): ")
                        if cron_schedule is None:
                            break
                        if cron_schedule == 'main':
                            return 'main'
                        try:
                            from apscheduler.triggers.cron import CronTrigger
                            trigger = CronTrigger.from_crontab(cron_schedule)
                            break
                        except ValueError:
                            print("Invalid cron format")
                            continue
                    
                # Update task without removing it
                self.scheduler.scheduler.reschedule_job(
                    job_id=task_id,
                    trigger=trigger
                )
                self.scheduler.save_tasks()
                print("Schedule updated")
                    
            elif choice == "3":
                new_description = self.get_valid_input("New description (b: back): ")
                if new_description is None:
                    continue
                if new_description == 'main':
                    return 'main'
                    
                # Update task without removing it
                self.scheduler.scheduler.modify_job(
                    job_id=task_id,
                    args=[current_task['command'], new_description, current_task['notifications_enabled']]
                )
                self.scheduler.save_tasks()
                print("Description updated")
                    
            elif choice == "4":
                current_status = "on" if current_task['notifications_enabled'] else "off"
                print(f"Notifications: {current_status}")
                
                if self.get_valid_input(f"Toggle notifications? (y/n): ", valid_options=["y", "n"]).lower() == 'y':
                    new_notifications_enabled = not current_task['notifications_enabled']
                    # Update task without removing it
                    self.scheduler.scheduler.modify_job(
                        job_id=task_id,
                        args=[current_task['command'], current_task['description'], new_notifications_enabled]
                    )
                    self.scheduler.save_tasks()
                    new_status = "on" if new_notifications_enabled else "off"
                    print(f"Notifications: {new_status}")
                else:
                    print("No change")
                    
            input("\nEnter to continue...")
            self.clear_screen()
            print("Edit Task")
            self.display_task_table(self.scheduler.list_tasks())
            
    def run(self):
        while True:
            self.display_menu()
            choice = self.get_valid_input("\nChoice: ", valid_options=["1", "2", "3", "4", "5"])
            if choice is None:
                continue
                
            result = None
            
            if choice == "1":
                result = self.add_task()
            elif choice == "2":
                self.list_tasks()
            elif choice == "3":
                result = self.edit_task()
            elif choice == "4":
                result = self.remove_task()
            elif choice == "5":
                if self.get_valid_input("Exit? (y/n): ", valid_options=["y", "n"]).lower() == 'y':
                    self.scheduler.shutdown()
                    break
                
            if result == 'main':
                continue 