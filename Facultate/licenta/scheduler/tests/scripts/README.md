# Scheduler Test Scripts

This directory contains various test scripts designed to validate the scheduler's ability to handle different types of tasks and system loads. Each script simulates a specific type of workload to test the scheduler's performance, error handling, and resource management capabilities.

## Test Scripts Overview

### Resource-Intensive Tests

#### `cpu_intensive.sh`
- **Purpose**: Tests CPU-bound task handling
- **Functionality**: Calculates prime numbers up to 1,000,000 using a brute-force algorithm
- **Output**: Writes found prime numbers to `../primes.txt`
- **Duration**: Variable (depends on system performance)
- **Use Case**: Validates scheduler performance under high CPU load

#### `memory_intensive.sh`
- **Purpose**: Tests memory-bound task handling
- **Functionality**: 
  - Creates 5 large NumPy arrays (1000x1000 each)
  - Performs matrix operations (squaring and multiplication)
  - Keeps arrays in memory for 2 seconds
- **Dependencies**: Requires Python 3 with NumPy
- **Use Case**: Validates scheduler behavior with memory-intensive operations

#### `disk_io.sh`
- **Purpose**: Tests disk I/O intensive operations
- **Functionality**:
  - Creates 5 files of 100MB each using random data
  - Reads each file and calculates MD5 checksums
  - Cleans up temporary files
- **Output**: Creates temporary directory `../disk_test/` with files and checksums
- **Use Case**: Validates scheduler performance during heavy disk operations

#### `network_intensive.sh`
- **Purpose**: Tests network-bound task handling
- **Functionality**:
  - Makes concurrent HTTP requests to 5 different websites
  - Uses ThreadPoolExecutor with 5 workers
  - Reports status codes and response sizes
- **Dependencies**: Requires Python 3 with requests library
- **Target URLs**: Google, GitHub, Python.org, Stack Overflow, Reddit
- **Use Case**: Validates scheduler behavior with network-dependent tasks

### Basic Functionality Tests

#### `long_running.sh`
- **Purpose**: Tests long-running task handling
- **Functionality**: Simple sleep for 15 seconds
- **Duration**: Exactly 15 seconds
- **Use Case**: Validates scheduler's ability to handle tasks that take significant time to complete

#### `file_writer.sh`
- **Purpose**: Tests basic file output functionality
- **Functionality**: Appends timestamp to `../output.txt`
- **Output**: Simple timestamp entries
- **Use Case**: Validates basic task execution and file I/O

#### `error_task.sh`
- **Purpose**: Tests error handling and failure scenarios
- **Functionality**: Intentionally exits with error code 1
- **Expected Behavior**: Should trigger scheduler's error handling mechanisms
- **Use Case**: Validates scheduler's ability to handle and report task failures

## Usage Instructions

### Prerequisites
- Ensure all scripts have execute permissions: `chmod +x *.sh`
- For Python-based scripts, install required dependencies:
  ```bash
  pip install numpy requests
  ```

### Running Tests
1. **Individual Tests**: Execute any script directly to see its output
   ```bash
   ./cpu_intensive.sh
   ```

2. **Scheduler Integration**: Add scripts to the scheduler with appropriate intervals
   - CPU/Memory intensive: Use longer intervals (5-10 minutes)
   - Network/IO intensive: Use moderate intervals (2-5 minutes)
   - Basic tests: Use shorter intervals (30 seconds - 2 minutes)

### Monitoring
- Check `../output.txt` for basic test results
- Check `../primes.txt` for CPU test results
- Monitor system resources during intensive tests
- Review scheduler logs for execution details and errors

## Test Scenarios

### Performance Testing
- Run multiple resource-intensive scripts simultaneously
- Monitor system resource usage (CPU, memory, disk, network)
- Verify scheduler maintains responsiveness

### Error Handling
- Use `error_task.sh` to test failure scenarios
- Verify error reporting and logging
- Ensure other tasks continue running

### Resource Management
- Test with various combinations of intensive scripts
- Verify scheduler doesn't overwhelm system resources
- Check for proper cleanup after task completion

### Scheduling Accuracy
- Use `long_running.sh` to test timing accuracy
- Verify tasks start at scheduled intervals
- Check for proper task queuing and execution order

## Notes

- **Resource Usage**: CPU and memory intensive tests can significantly impact system performance
- **Network Dependencies**: Network tests require internet connectivity
- **Cleanup**: Disk I/O test automatically cleans up temporary files
- **Logging**: All scripts provide timestamped output for debugging
- **Error Codes**: Use exit codes to verify proper error handling in the scheduler 