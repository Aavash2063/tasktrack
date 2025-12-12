#include <iostream>
#include <string>
#include "../include/Task.h"
#include "../include/TaskList.h"

using namespace std;

int main() {
    TaskList list;

    cout << "=== TaskTrack (Checkpoint 1) ===\n";
    cout << "Add one task and display tasks.\n\n";

    string title;
    string category;

    cout << "Enter task title: ";
    getline(cin, title);

    cout << "Enter category (Work/Study/Personal): ";
    getline(cin, category);

    Task t(title, category, ""); // createdDate not required yet
    list.addTask(t);

    cout << "\nTask added.\n";
    list.displayAllTasks();

    cout << "\nDone.\n";
    return 0;
}
