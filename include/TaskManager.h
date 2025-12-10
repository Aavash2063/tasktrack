#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include "TaskList.h"
#include "FileHandler.h"
#include "UserInterface.h"

/**
 * TaskManager coordinates the overall flow of the program.
 * It holds the TaskList, FileHandler, and UserInterface instances,
 * and runs the main loop.
 */
class TaskManager {
private:
    TaskList taskList;
    FileHandler fileHandler;
    UserInterface ui;
    bool running;

    void loadData();
    void saveData() const;

public:
    // Constructors
    TaskManager();
    TaskManager(const std::string& dataFile);

    // Main loop
    void run();
};

#endif // TASKMANAGER_H
