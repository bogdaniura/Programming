#!/bin/bash

echo "Starting disk I/O intensive task at $(date)"
WORK_DIR="/home/kgbeast/Bogdan/Programming/Facultate/licenta/scheduler/tests/disk_test"

# Create test directory
mkdir -p "$WORK_DIR"

# Generate and write large files
for i in {1..5}; do
    echo "Creating file $i"
    dd if=/dev/urandom of="$WORK_DIR/file$i.dat" bs=1M count=100
done

# Read and process files
for i in {1..5}; do
    echo "Processing file $i"
    # Read file and perform some operations
    cat "$WORK_DIR/file$i.dat" | md5sum >> "$WORK_DIR/checksums.txt"
done

# Clean up
echo "Cleaning up..."
rm -rf "$WORK_DIR"
echo "Finished disk I/O intensive task at $(date)" 