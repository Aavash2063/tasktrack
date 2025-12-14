#ifndef TASKLIST_H
#define TASKLIST_H

#include <vector>
#include <string>
#include "Task.h"

class TaskList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task);
    void markTaskCompleted(int index);
    void displayAllTasks() const;

    // Checkpoint 3 feature
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};

#endif
