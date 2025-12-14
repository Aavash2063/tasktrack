#include "../include/TaskList.h"
#include <iostream>
#include <fstream>

void TaskList::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskList::markTaskCompleted(int index) {
    if (index < 0 || index >= (int)tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks[index].setCompleted(true);
}

void TaskList::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". ";
        tasks[i].display();
    }
}

bool TaskList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) return false;

    for (const Task& t : tasks) {
        file << t.serialize() << std::endl;
    }
    return true;
}

bool TaskList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;

    tasks.clear();
    std::string line;

    while (std::getline(file, line)) {
        tasks.push_back(Task::deserialize(line));
    }
    return true;
}
