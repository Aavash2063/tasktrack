#include <iostream>
#include <string>
#include "../include/TaskManager.h"

using namespace std;

int main() {
    // Data file for storing tasks
    TaskManager manager("tasks.txt");

    // Start the main loop
    manager.run();

    return 0;
}
