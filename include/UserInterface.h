#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include "TaskList.h"

/**
 * UserInterface handles console input/output.
 * It shows menus, prompts the user, and calls into TaskList
 * for the actual operations.
 */
class UserInterface {
public:
    // Menu display
    void displayMainMenu() const;

    // Input handling
    int getMenuChoice() const;
    std::string promptForTitle() const;
    std::string promptForCategory() const;
    std::string promptForDate() const;

    // High-level actions
    void handleAddTask(TaskList& list) const;
    void handleEditTask(TaskList& list) const;
    void handleDeleteTask(TaskList& list) const;
    void handleMarkCompleted(TaskList& list) const;
    void handleShowSummary(const TaskList& list) const;
    void handleShowAllTasks(const TaskList& list) const;
};

#endif // USERINTERFACE_H
