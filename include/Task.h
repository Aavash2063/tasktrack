#ifndef TASK_H
#define TASK_H

#include <string>

/**
 * Task represents a single to-do item in the system.
 * It keeps track of a title, category, completion status,
 * and a simple creation date stored as a string.
 */
class Task {
private:
    std::string title;
    std::string category;
    bool completed;
    std::string createdDate; // Simple date string, e.g., "2025-12-10"

public:
    // Constructors
    Task();
    Task(const std::string& taskTitle);
    Task(const std::string& taskTitle,
         const std::string& taskCategory,
         const std::string& dateCreated);

    // Getters
    std::string getTitle() const;
    std::string getCategory() const;
    bool isCompleted() const;
    std::string getCreatedDate() const;

    // Setters
    void setTitle(const std::string& taskTitle);
    void setCategory(const std::string& taskCategory);
    void setCompleted(bool status);
    void setCreatedDate(const std::string& dateCreated);

    // Core functionality
    void toggleCompleted();           // Flip completion state
    void display() const;             // Print task details to console
};

#endif // TASK_H
