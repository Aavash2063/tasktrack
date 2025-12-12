#include "../include/Task.h"
#include <iostream>

Task::Task()
    : title("Untitled"), category("Uncategorized"), completed(false), createdDate("") {
}

Task::Task(const std::string& taskTitle)
    : title(taskTitle), category("Uncategorized"), completed(false), createdDate("") {
}

Task::Task(const std::string& taskTitle,
           const std::string& taskCategory,
           const std::string& dateCreated)
    : title(taskTitle), category(taskCategory), completed(false), createdDate(dateCreated) {
}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getCategory() const {
    return category;
}

bool Task::isCompleted() const {
    return completed;
}

std::string Task::getCreatedDate() const {
    return createdDate;
}

void Task::setTitle(const std::string& taskTitle) {
    title = taskTitle;
}

void Task::setCategory(const std::string& taskCategory) {
    category = taskCategory;
}

void Task::setCompleted(bool status) {
    completed = status;
}

void Task::setCreatedDate(const std::string& dateCreated) {
    createdDate = dateCreated;
}

void Task::toggleCompleted() {
    completed = !completed;
}

void Task::display() const {
    std::cout << "- " << title
              << " [" << category << "] "
              << (completed ? "(Done)" : "(Pending)");

    if (!createdDate.empty()) {
        std::cout << " Created: " << createdDate;
    }

    std::cout << std::endl;
}
