#!/usr/bin/env python3
import sys
import os
import daemon
import logging
from pathlib import Path
from .menu import SchedulerMenu

def setup_logging():
    log_dir = Path("logs")
    log_dir.mkdir(exist_ok=True)
    
    logging.basicConfig(
        filename=log_dir / "scheduler.log",
        level=logging.INFO,
        format='%(asctime)s - %(levelname)s - %(message)s'
    )

def run_scheduler():
    setup_logging()
    menu = SchedulerMenu()
    menu.run()

def main():
    run_scheduler()

if __name__ == "__main__":
    main() 