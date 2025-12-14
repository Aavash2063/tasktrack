#include <iostream>
#include "../include/TaskList.h"

int main() {
    TaskList list;
    list.loadFromFile("tasks.txt");

    int choice;
    std::string title, category;

    while (true) {
        std::cout << "\n1. Add task\n2. Display tasks\n3. Mark task completed\n4. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::cout << "Title: ";
            std::getline(std::cin, title);
            std::cout << "Category: ";
            std::getline(std::cin, category);
            list.addTask(Task(title, category));
        }
        else if (choice == 2) {
            list.displayAllTasks();
        }
        else if (choice == 3) {
            int num;
            std::cout << "Task number: ";
            std::cin >> num;
            list.markTaskCompleted(num - 1);
        }
        else if (choice == 4) {
            list.saveToFile("tasks.txt");
            break;
        }
    }

    return 0;
}
