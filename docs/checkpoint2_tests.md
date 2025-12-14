# Checkpoint 2 Test Cases

## Feature: Mark Task as Completed

### Test Setup
- Program: TaskTrack
- Feature tested: Mark task as completed
- Platform: macOS
- Build system: CMake

---

### Test 1: Normal Operation
**Steps**
1. Add a task with a title and category
2. Choose "Mark task as completed"
3. Enter task number 1
4. Display tasks

**Expected Result**
- Task status changes from Pending to Done

**Result**
- Pass

---

### Test 2: Edge Case – No Tasks
**Steps**
1. Start the program
2. Choose "Mark task as completed" without adding tasks

**Expected Result**
- Program does not crash
- User sees an error or no change

**Result**
- Pass

---

### Test 3: Boundary Condition – Invalid Task Number
**Steps**
1. Add one task
2. Enter a task number that does not exist (e.g., 5)

**Expected Result**
- Program shows an invalid task message
- No crash

**Result**
- Pass
