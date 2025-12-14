#include "../include/Task.h"
#include <iostream>
#include <sstream>

Task::Task() : title(""), category(""), completed(false) {}

Task::Task(const std::string& t, const std::string& c)
    : title(t), category(c), completed(false) {}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getCategory() const {
    return category;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool value) {
    completed = value;
}

std::string Task::serialize() const {
    return title + "|" + category + "|" + (completed ? "1" : "0");
}

Task Task::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string t, c, done;

    std::getline(ss, t, '|');
    std::getline(ss, c, '|');
    std::getline(ss, done);

    Task task(t, c);
    task.setCompleted(done == "1");
    return task;
}

void Task::display() const {
    std::cout << "- " << title << " [" << category << "] "
              << (completed ? "(Done)" : "(Pending)") << std::endl;
}
