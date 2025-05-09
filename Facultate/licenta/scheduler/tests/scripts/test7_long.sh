#!/bin/bash

# Test script that simulates a long-running task
echo "$(date '+%Y-%m-%d %H:%M:%S') - Test 7 started" >> /tmp/scheduler_test7.txt
sleep 15  # Simulate work
echo "$(date '+%Y-%m-%d %H:%M:%S') - Test 7 completed" >> /tmp/scheduler_test7.txt 