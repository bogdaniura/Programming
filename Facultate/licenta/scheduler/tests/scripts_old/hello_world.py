#!/usr/bin/env python3
import os
import time
import subprocess

# Command to open a new Konsole window and run the echo command
command = "konsole -e 'bash -c \"echo Hello World!; sleep 5; exit\"'"

# Execute the command
subprocess.run(command, shell=True)