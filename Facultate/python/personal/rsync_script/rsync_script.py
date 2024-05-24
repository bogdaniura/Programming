#!/usr/bin/env python3

import os
import subprocess
import sys

def main():
    # Source and destination directories
    source_dir = "/home/kgbeast/Bogdan/Programming/Facultate/python/personal/rsync_script/test_source"
    dest_dir = "/home/kgbeast/Bogdan/Programming/Facultate/python/personal/rsync_script/test_destination"
    exclude_file = "/home/kgbeast/Bogdan/Programming/Facultate/python/personal/rsync_script/exceptions.txt"

    # Ensure the script is run as root
    if os.geteuid() != 0:
        print("This script must be run as root")
        sys.exit(1)

    # Check if source directory exists
    if not os.path.isdir(source_dir):
        print(f"Source directory {source_dir} does not exist.")
        sys.exit(1)

    # Check if destination directory exists
    if not os.path.isdir(dest_dir):
        print(f"Destination directory {dest_dir} does not exist.")
        sys.exit(1)

    # Check if exclusion file exists
    if not os.path.isfile(exclude_file):
        print(f"Exclusion file {exclude_file} does not exist.")
        sys.exit(1)

    # Construct the rsync command
    rsync_command = [
        "rsync", "-avz",
        "--exclude-from", exclude_file,
        f"{source_dir}/", f"{dest_dir}/"
    ]

    try:
        # Execute the rsync command
        result = subprocess.run(rsync_command, check=True, text=True, capture_output=True)
        print(result.stdout)
        print("Files copied successfully.")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred during file copying: {e.stderr}")
        sys.exit(1)

if __name__ == "__main__":
    main()
