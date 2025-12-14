#include <iostream>
#include <string>
#include "../include/Task.h"
#include "../include/TaskList.h"

using namespace std;

void showMenu() {
    cout << "\n=== TaskTrack Menu ===\n";
    cout << "1. Add task\n";
    cout << "2. Display tasks\n";
    cout << "3. Mark task as completed\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    TaskList list;
    int choice = 0;

    cout << "=== TaskTrack (Checkpoint 2) ===\n";

    while (choice != 4) {
        showMenu();
        cin >> choice;
        cin.ignore(); // clear newline

        if (choice == 1) {
            string title, category;

            cout << "Enter task title: ";
            getline(cin, title);

            cout << "Enter category (Work/Study/Personal): ";
            getline(cin, category);

            Task t(title, category, "");
            list.addTask(t);

            cout << "Task added.\n";
        }
        else if (choice == 2) {
            list.displayAllTasks();
        }
        else if (choice == 3) {
            int taskNumber;
            cout << "Enter task number to mark completed: ";
            cin >> taskNumber;

            list.markTaskCompleted(taskNumber - 1);
        }
        else if (choice == 4) {
            cout << "Exiting TaskTrack.\n";
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
