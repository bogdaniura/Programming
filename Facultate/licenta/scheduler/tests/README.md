# Scheduler Test Scripts

This directory contains test scripts to verify different functionalities of the scheduler.

## Test Scripts

1. `test1_basic.sh` - Basic task test
   - Runs every 10 seconds
   - Writes timestamp to `/tmp/scheduler_test1.txt`

2. `test2_date.sh` - Task persistence test
   - Runs every minute
   - Writes date to `/tmp/scheduler_test2.txt`

3. Multiple tasks test:
   - `test3a.sh` - Runs every 10 seconds
   - `test3b.sh` - Runs every 30 seconds
   - `test3c.sh` - Runs every minute

4. `test4_removal.sh` - Task removal test
   - Runs every 15 seconds
   - Writes to `/tmp/scheduler_test4.txt`

5. `test5_onetime.sh` - One-time task test
   - Runs once at specified time
   - Writes to `/tmp/scheduler_test5.txt`

6. `test6_complex.sh` - Complex schedule test
   - Runs every 2 minutes
   - Writes to `/tmp/scheduler_test6.txt`

7. `test7_long.sh` - Long-running task test
   - Takes 15 seconds to complete
   - Writes to `/tmp/scheduler_test7.txt`

8. `test8_notifications.sh` - Notification test
   - Writes to `/tmp/scheduler_test8.txt`

## How to Run Tests

1. Start the scheduler:
```bash
python -m src.main
```

2. Add tasks using the menu:
   - Choose option 1 (Add new task)
   - Enter the full path to the test script
   - Set appropriate schedule
   - Add description

3. Monitor the output files in `/tmp/`

4. Check the scheduler logs in `logs/scheduler.log`

## Test Scenarios

1. **Basic Task Test**
   - Add test1_basic.sh with 10-second interval
   - Verify file is created and updated
   - Check notifications

2. **Persistence Test**
   - Add test2_date.sh with 1-minute interval
   - Stop and restart scheduler
   - Verify task continues

3. **Multiple Tasks**
   - Add all three test3 scripts
   - Verify correct intervals
   - Check no interference

4. **Task Removal**
   - Add test4_removal.sh
   - Let it run
   - Remove task
   - Verify it stops

5. **Error Handling**
   - Add invalid command
   - Verify error handling
   - Check other tasks

6. **One-time Task**
   - Add test5_onetime.sh
   - Set future time
   - Verify single execution

7. **Complex Schedule**
   - Add test6_complex.sh
   - Set 2-minute interval
   - Verify timing

8. **Long-running Task**
   - Add test7_long.sh
   - Set 10-second interval
   - Check overlapping

9. **Notifications**
   - Add test8_notifications.sh
   - Verify success notification
   - Add failing task
   - Verify error notification 