#ifndef TASKLIST_H
#define TASKLIST_H

#include <vector>
#include <string>
#include "Task.h"

/**
 * TaskList manages a collection of Task objects.
 * It is responsible for adding, removing, updating, and summarizing tasks.
 */
class TaskList {
private:
    std::vector<Task> tasks;

    // Helper: find index of task by title, returns -1 if not found
    int findTaskIndexByTitle(const std::string& title) const;

public:
    // Constructors
    TaskList();

    // Basic operations
    void addTask(const Task& task);
    bool removeTask(const std::string& title);
    bool markTaskCompleted(const std::string& title);
    bool editTaskTitle(const std::string& oldTitle, const std::string& newTitle);
    bool editTaskCategory(const std::string& title, const std::string& newCategory);

    // Summary / queries
    int getTotalTaskCount() const;
    int getCompletedTaskCount() const;
    int getPendingTaskCount() const;
    double getCompletionPercentage() const; // 0.0 to 100.0

    // Display helpers
    void displayAllTasks() const;
    void displayTasksByCategory(const std::string& category) const;

    // Access to underlying data if needed
    const std::vector<Task>& getTasks() const;
};

#endif // TASKLIST_H
