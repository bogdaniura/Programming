#!/bin/bash

echo "Starting memory intensive task at $(date)"
# Create a Python script for memory operations
cat > /tmp/memory_test.py << 'EOF'
import numpy as np
import time

# Allocate large arrays
print("Allocating arrays...")
arrays = []
for i in range(5):
    # Create a 1000x1000 array of random numbers
    arr = np.random.rand(1000, 1000)
    arrays.append(arr)
    print(f"Allocated array {i+1}")

# Perform some operations
print("Performing operations...")
for i in range(len(arrays)):
    arrays[i] = arrays[i] * arrays[i]  # Square the array
    arrays[i] = np.matmul(arrays[i], arrays[i])  # Matrix multiplication

print("Operations completed")
time.sleep(2)  # Keep arrays in memory for a while
EOF

# Run the Python script
python3 /tmp/memory_test.py
echo "Finished memory intensive task at $(date)" 