# Checkpoint 3: Third Feature Plan

## Feature Name
Save and Load Tasks

## Description
This feature allows tasks to be saved to a file when the program exits and loaded automatically when the program starts. This ensures that tasks are not lost between runs.

## Why This Feature?
So far, tasks only exist while the program is running. Saving and loading tasks makes the application practical for real use and completes the basic task tracking workflow.

## Classes Involved
- Task
- TaskList
- main.cpp

## Expected User Workflow
When the program starts, it checks for an existing data file and loads tasks if available. When the user exits, all current tasks are saved automatically.

## Estimated Time
3 to 4 hours
