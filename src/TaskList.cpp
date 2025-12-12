#include "../include/TaskList.h"
#include <iostream>

TaskList::TaskList() : tasks() {
}

int TaskList::findTaskIndexByTitle(const std::string& title) const {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTitle() == title) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void TaskList::addTask(const Task& task) {
    tasks.push_back(task);
}

bool TaskList::removeTask(const std::string& title) {
    int index = findTaskIndexByTitle(title);
    if (index == -1) return false;

    tasks.erase(tasks.begin() + index);
    return true;
}

bool TaskList::markTaskCompleted(const std::string& title) {
    int index = findTaskIndexByTitle(title);
    if (index == -1) return false;

    tasks[index].setCompleted(true);
    return true;
}

bool TaskList::editTaskTitle(const std::string& oldTitle, const std::string& newTitle) {
    int index = findTaskIndexByTitle(oldTitle);
    if (index == -1) return false;

    tasks[index].setTitle(newTitle);
    return true;
}

bool TaskList::editTaskCategory(const std::string& title, const std::string& newCategory) {
    int index = findTaskIndexByTitle(title);
    if (index == -1) return false;

    tasks[index].setCategory(newCategory);
    return true;
}

int TaskList::getTotalTaskCount() const {
    return static_cast<int>(tasks.size());
}

int TaskList::getCompletedTaskCount() const {
    int count = 0;
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].isCompleted()) count++;
    }
    return count;
}

int TaskList::getPendingTaskCount() const {
    return getTotalTaskCount() - getCompletedTaskCount();
}

double TaskList::getCompletionPercentage() const {
    int total = getTotalTaskCount();
    if (total == 0) return 0.0;

    return (static_cast<double>(getCompletedTaskCount()) / total) * 100.0;
}

void TaskList::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks yet.\n";
        return;
    }

    std::cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << (i + 1) << ". ";
        tasks[i].display();
    }
}

void TaskList::displayTasksByCategory(const std::string& category) const {
    bool found = false;
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].getCategory() == category) {
            found = true;
            tasks[i].display();
        }
    }

    if (!found) {
        std::cout << "No tasks found in category: " << category << std::endl;
    }
}

const std::vector<Task>& TaskList::getTasks() const {
    return tasks;
}
