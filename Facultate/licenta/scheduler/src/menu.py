import os
from datetime import datetime
from rich.console import Console
from rich.table import Table
from rich.prompt import Prompt, Confirm
from .scheduler import TaskScheduler

class SchedulerMenu:
    def __init__(self):
        self.console = Console()
        self.scheduler = TaskScheduler()
        self.scheduler.start()
        
    def clear_screen(self):
        os.system('clear' if os.name == 'posix' else 'cls')
        
    def display_header(self):
        self.console.print("\n[bold blue]Task Scheduler[/bold blue]")
        self.console.print("=" * 50)
        
    def display_menu(self):
        self.clear_screen()
        self.display_header()
        self.console.print("\n[bold]Main Menu:[/bold]")
        self.console.print("1. Add new task")
        self.console.print("2. List all tasks")
        self.console.print("3. Remove task")
        self.console.print("4. Exit")
        
    def add_task(self):
        self.clear_screen()
        self.display_header()
        self.console.print("\n[bold]Add New Task[/bold]")
        
        task_id = Prompt.ask("Enter task ID")
        command = Prompt.ask("Enter command to execute")
        description = Prompt.ask("Enter task description (optional)", default="")
        
        task_type = Prompt.ask(
            "Select task type",
            choices=["one-time", "recurring"],
            default="recurring"
        )
        
        if task_type == "one-time":
            date_str = Prompt.ask(
                "Enter date and time (YYYY-MM-DD HH:MM:SS)",
                default=datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            )
            schedule = datetime.strptime(date_str, "%Y-%m-%d %H:%M:%S").isoformat()
            is_cron = False
        else:
            schedule_type = Prompt.ask(
                "Select schedule type",
                choices=["cron", "interval"],
                default="cron"
            )
            
            if schedule_type == "interval":
                seconds = Prompt.ask("Enter interval in seconds", default="10")
                schedule = f"interval:{seconds}"
                is_cron = True  # We still use is_cron=True for interval tasks
            else:
                self.console.print("\n[bold]Cron Schedule Format:[/bold]")
                self.console.print("minute hour day month weekday")
                self.console.print("Example: */15 * * * * (every 15 minutes)")
                schedule = Prompt.ask("Enter cron schedule")
                is_cron = True
            
        if self.scheduler.add_task(task_id, command, schedule, is_cron, description):
            self.console.print("\n[green]Task added successfully![/green]")
        else:
            self.console.print("\n[red]Failed to add task![/red]")
            
        input("\nPress Enter to continue...")
        
    def list_tasks(self):
        self.clear_screen()
        self.display_header()
        self.console.print("\n[bold]Scheduled Tasks[/bold]")
        
        tasks = self.scheduler.list_tasks()
        if not tasks:
            self.console.print("\n[yellow]No tasks scheduled[/yellow]")
        else:
            table = Table(show_header=True, header_style="bold magenta")
            table.add_column("ID")
            table.add_column("Command")
            table.add_column("Schedule")
            table.add_column("Next Run")
            table.add_column("Description")
            
            for task in tasks:
                table.add_row(
                    task['id'],
                    task['command'],
                    str(task['schedule']),
                    str(task['next_run']),
                    task['description']
                )
                
            self.console.print(table)
            
        input("\nPress Enter to continue...")
        
    def remove_task(self):
        self.clear_screen()
        self.display_header()
        self.console.print("\n[bold]Remove Task[/bold]")
        
        tasks = self.scheduler.list_tasks()
        if not tasks:
            self.console.print("\n[yellow]No tasks to remove[/yellow]")
            input("\nPress Enter to continue...")
            return
            
        table = Table(show_header=True, header_style="bold magenta")
        table.add_column("ID")
        table.add_column("Command")
        table.add_column("Schedule")
        
        for task in tasks:
            table.add_row(
                task['id'],
                task['command'],
                str(task['schedule'])
            )
            
        self.console.print(table)
        
        task_id = Prompt.ask("\nEnter task ID to remove")
        if Confirm.ask(f"Are you sure you want to remove task {task_id}?"):
            if self.scheduler.remove_task(task_id):
                self.console.print("\n[green]Task removed successfully![/green]")
            else:
                self.console.print("\n[red]Failed to remove task![/red]")
                
        input("\nPress Enter to continue...")
        
    def run(self):
        while True:
            self.display_menu()
            choice = Prompt.ask(
                "\nSelect an option",
                choices=["1", "2", "3", "4"],
                default="4"
            )
            
            if choice == "1":
                self.add_task()
            elif choice == "2":
                self.list_tasks()
            elif choice == "3":
                self.remove_task()
            elif choice == "4":
                if Confirm.ask("Are you sure you want to exit?"):
                    self.scheduler.shutdown()
                    break 