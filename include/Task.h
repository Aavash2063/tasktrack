#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string title;
    std::string category;
    bool completed;

public:
    Task();
    Task(const std::string& title, const std::string& category);

    std::string getTitle() const;
    std::string getCategory() const;
    bool isCompleted() const;

    void setCompleted(bool value);

    // File I/O helpers
    std::string serialize() const;
    static Task deserialize(const std::string& line);

    void display() const;
};

#endif
