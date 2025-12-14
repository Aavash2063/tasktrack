# Checkpoint 2 Reflection

## What I Implemented
For this checkpoint, I added the ability to mark tasks as completed. The user can select a task from the list using its number, and the task status updates immediately.

## Integration with First Feature
This feature builds directly on the task creation feature from Checkpoint 1. Tasks must already exist before they can be marked completed, so the two features work together naturally.

## Challenges Faced
The main challenge was keeping the header and implementation files consistent. A small typo caused a compile error, which helped me understand how important matching function names is in C++.

## What I Learned
I learned how to extend existing classes instead of rewriting code. I also became more comfortable debugging compiler errors and using Git commits to track progress.

## Testing Results
All test cases passed, including normal use, edge cases, and invalid input handling.

## Design Decisions
I chose to use task numbers instead of task titles for completion because it is simpler for users and avoids duplicate title issues.

## Questions for Next Checkpoint
How can file saving be added cleanly without overcomplicating the code?

## Time Spent
Approximately 3 hours
