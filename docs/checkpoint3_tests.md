# Checkpoint 3 – Test Results

## Test 1: Save and Load Tasks
Added multiple tasks, saved them to a file, cleared the list, and loaded the file again.
All tasks were restored correctly with their original titles, categories, and completion status.

## Test 2: Completion Persistence
Marked a task as completed, saved the tasks, and reloaded them.
The completed task remained marked as completed after loading.

## Test 3: Load Failure Handling
Attempted to load from a file that does not exist.
The program handled the failure without crashing and continued running normally.

All automated tests passed using CTest.
