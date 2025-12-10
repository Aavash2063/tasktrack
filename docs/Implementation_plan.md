{\rtf1\ansi\ansicpg1252\cocoartf2865
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 # TaskTrack \'96 Implementation Plan\
\
## Feature 1: Add New Task\
\
**Trigger**:  \
User selects "Add new task" from the main menu.\
\
**Input Needed**:\
- Task title (string)\
- Category (string, e.g., "Work", "Study", "Personal")\
- Creation date (string, simple format like "2025-12-10")\
\
**Implementation Flow**:\
1. In `TaskManager::run()`:\
   - Call `ui.displayMainMenu()` and get the user\'92s choice with `ui.getMenuChoice()`.\
   - If user chooses the "Add task" option, call `ui.handleAddTask(taskList)`.\
\
2. In `UserInterface::handleAddTask(TaskList& list)`:\
   - Call `promptForTitle()` to get a non-empty title from the user.\
   - Call `promptForCategory()` to get a category.\
   - Call `promptForDate()` to get a date string (or generate a default).\
   - Create a `Task` object using the constructor:\
     - `Task newTask(title, category, date);`\
   - Call `list.addTask(newTask)` to add it to the collection.\
   - Print a confirmation message (e.g., "Task added successfully.").\
\
3. `TaskList::addTask(const Task& task)`:\
   - Push the task onto the internal `tasks` vector.\
   - Optionally print a small debug or confirmation message.\
\
**Data Modified**:\
- New `Task` object created.\
- `TaskList::tasks` vector grows by one element.\
\
**Completion**:\
- User sees a confirmation and is returned to the main menu.\
\
**Functions Used**:\
- `UserInterface::displayMainMenu()`\
- `UserInterface::getMenuChoice()`\
- `UserInterface::handleAddTask(TaskList&)`\
- `UserInterface::promptForTitle()`\
- `UserInterface::promptForCategory()`\
- `UserInterface::promptForDate()`\
- `Task::Task(const std::string&, const std::string&, const std::string&)`\
- `TaskList::addTask(const Task&)`\
\
---\
\
## Feature 2: Edit or Delete an Existing Task\
\
**Trigger**:  \
User selects "Edit task" or "Delete task" from the main menu.\
\
**Input Needed**:\
- Existing task title (string) to identify the task.\
- For editing: new title or new category (strings).\
\
**Implementation Flow**:\
1. In `TaskManager::run()`:\
   - After menu selection, if user chooses "Edit task", call `ui.handleEditTask(taskList)`.\
   - If user chooses "Delete task", call `ui.handleDeleteTask(taskList)`.\
\
2. `UserInterface::handleEditTask(TaskList& list)`:\
   - Call `promptForTitle()` to get the current task title.\
   - Ask user whether they want to change the title or category.\
   - If changing title:\
     - Prompt for new title.\
     - Call `list.editTaskTitle(oldTitle, newTitle)`.\
   - If changing category:\
     - Prompt for new category.\
     - Call `list.editTaskCategory(title, newCategory)`.\
   - Print whether the edit succeeded or if the task was not found.\
\
3. `UserInterface::handleDeleteTask(TaskList& list)`:\
   - Call `promptForTitle()` to get the title of the task to remove.\
   - Call `list.removeTask(title)`.\
   - Print a confirmation or \'93task not found\'94 message.\
\
4. `TaskList` methods:\
   - `removeTask(const std::string& title)`:\
     - Uses `findTaskIndexByTitle(title)` to locate the index.\
     - If found, erase it from `tasks` vector and return true.\
     - Otherwise, return false.\
   - `editTaskTitle(const std::string& oldTitle, const std::string& newTitle)`:\
     - Find the task and update its `title`.\
   - `editTaskCategory(const std::string& title, const std::string& newCategory)`:\
     - Find the task and update its `category`.\
\
**Data Modified**:\
- For edit: fields inside an existing `Task` object are changed.\
- For delete: an element is removed from `TaskList::tasks`.\
\
**Completion**:\
- User sees whether the change or deletion was successful.\
\
**Functions Used**:\
- `UserInterface::handleEditTask(TaskList&)`\
- `UserInterface::handleDeleteTask(TaskList&)`\
- `UserInterface::promptForTitle()`\
- `TaskList::removeTask(const std::string&)`\
- `TaskList::editTaskTitle(const std::string&, const std::string&)`\
- `TaskList::editTaskCategory(const std::string&, const std::string&)`\
\
---\
\
## Feature 3: Mark Task as Completed and Show Summary\
\
**Trigger**:  \
- User selects "Mark task as completed" from the main menu.  \
- User selects "Show summary" to view overall stats.\
\
**Input Needed**:\
- Task title (string) to mark as completed.\
\
**Implementation Flow**:\
1. In `TaskManager::run()`:\
   - For marking completion, call `ui.handleMarkCompleted(taskList)`.\
   - For summary, call `ui.handleShowSummary(taskList)`.\
\
2. `UserInterface::handleMarkCompleted(TaskList& list)`:\
   - Call `promptForTitle()` to get the title.\
   - Call `list.markTaskCompleted(title)`.\
   - If true, print "Task marked as completed."\
   - If false, print "Task not found."\
\
3. `TaskList::markTaskCompleted(const std::string& title)`:\
   - Use `findTaskIndexByTitle(title)`.\
   - If found, call `tasks[index].setCompleted(true)` or `tasks[index].toggleCompleted()`.\
   - Return true if successful, false otherwise.\
\
4. `UserInterface::handleShowSummary(const TaskList& list)`:\
   - Call `list.getTotalTaskCount()`, `list.getCompletedTaskCount()`, `list.getPendingTaskCount()`, and `list.getCompletionPercentage()`.\
   - Print a small report, for example:\
     - "Total tasks: X"\
     - "Completed: Y"\
     - "Pending: Z"\
     - "Completion: P%"\
\
**Data Modified**:\
- For marking completion: `Task::completed` field is updated.\
- Summary itself does not modify data; it just reads and prints it.\
\
**Completion**:\
- User gets quick feedback on progress through summary numbers and percentage.\
\
**Functions Used**:\
- `UserInterface::handleMarkCompleted(TaskList&)`\
- `UserInterface::handleShowSummary(const TaskList&)`\
- `UserInterface::promptForTitle()`\
- `TaskList::markTaskCompleted(const std::string&)`\
- `TaskList::getTotalTaskCount() const`\
- `TaskList::getCompletedTaskCount() const`\
- `TaskList::getPendingTaskCount() const`\
- `TaskList::getCompletionPercentage() const`\
\
---\
\
## Feature 4: Display All Tasks (with Optional Category Filter)\
\
**Trigger**:  \
User selects "View all tasks" from the main menu.\
\
**Input Needed**:\
- Optional: category string if user wants to filter.\
\
**Implementation Flow**:\
1. In `TaskManager::run()`:\
   - When user chooses "View tasks", call `ui.handleShowAllTasks(taskList)`.\
\
2. `UserInterface::handleShowAllTasks(const TaskList& list)`:\
   - Ask the user if they want to filter by category.\
   - If no filter:\
     - Call `list.displayAllTasks()`.\
   - If filter:\
     - Call `promptForCategory()` to get category.\
     - Call `list.displayTasksByCategory(category)`.\
\
3. `TaskList::displayAllTasks() const`:\
   - Loop through `tasks` vector.\
   - For each task, call `task.display()`.\
\
4. `TaskList::displayTasksByCategory(const std::string& category) const`:\
   - Loop through `tasks`.\
   - For each task, check if `task.getCategory() == category`.\
   - If it matches, call `task.display()`.\
\
**Data Modified**:\
- None; this is purely read-only.\
\
**Completion**:\
- User sees a list of tasks printed to the console, either all or filtered.\
\
**Functions Used**:\
- `UserInterface::handleShowAllTasks(const TaskList&)`\
- `UserInterface::promptForCategory()`\
- `TaskList::displayAllTasks() const`\
- `TaskList::displayTasksByCategory(const std::string&) const`\
- `Task::display() const`\
\
---\
\
## Feature 5: Save Tasks to File\
\
**Trigger**:  \
- User chooses "Save and exit" from the menu.\
- Or `TaskManager::run()` ends and calls `saveData()` before quitting.\
\
**Input Needed**:\
- No user input at this moment; uses internal `TaskList` and filename.\
\
**Implementation Flow**:\
1. In `TaskManager::run()`:\
   - When the user selects "Exit", set `running` to false.\
   - Before actually returning from `run()`, call `saveData()`.\
\
2. `TaskManager::saveData() const`:\
   - Call `fileHandler.save(taskList)`.\
\
3. `FileHandler::save(const TaskList& list) const`:\
   - Open an `ofstream` using `filename`.\
   - Write the number of tasks, or just write tasks line by line.\
   - For each `Task` in `list.getTasks()`:\
     - Write title, category, completion status, and created date in a consistent format.\
   - Close the file.\
   - Return true if successful, false otherwise.\
\
**Data Modified**:\
- No in-memory data changed.\
- Data file on disk is created or overwritten.\
\
**Completion**:\
- Tasks are saved so the user does not lose progress between runs.\
\
**Functions Used**:\
- `TaskManager::saveData() const`\
- `FileHandler::save(const TaskList&) const`\
- `TaskList::getTasks() const`\
- `Task::getTitle() const`\
- `Task::getCategory() const`\
- `Task::isCompleted() const`\
- `Task::getCreatedDate() const`\
\
---\
\
## Feature 6: Load Tasks from File\
\
**Trigger**:  \
Program start (inside `TaskManager` constructor or `run()` before showing menu).\
\
**Input Needed**:\
- No direct user input; relies on the data file if it exists.\
\
**Implementation Flow**:\
1. In `TaskManager` constructor or at the start of `run()`:\
   - Call `loadData()` once.\
\
2. `TaskManager::loadData()`:\
   - Call `fileHandler.load(taskList)`.\
\
3. `FileHandler::load(TaskList& list) const`:\
   - Open an `ifstream` using `filename`.\
   - If file does not exist, simply return false (no error message, just means no saved tasks yet).\
   - Otherwise:\
     - Clear existing tasks in `list` if desired.\
     - Read each stored task line by line.\
     - For each line, parse title, category, completion flag, and date.\
     - Construct a `Task` object and call `list.addTask(task)`.\
   - Close the file.\
\
**Data Modified**:\
- `TaskList::tasks` is filled with tasks from the file.\
\
**Completion**:\
- If data exists, the user starts with their previous tasks already loaded.\
\
**Functions Used**:\
- `TaskManager::loadData()`\
- `FileHandler::load(TaskList&) const`\
- `TaskList::addTask(const Task&)`\
- `Task` constructors and setters\
}