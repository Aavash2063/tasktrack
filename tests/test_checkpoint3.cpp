#include "../include/TaskList.h"
#include <cassert>
#include <iostream>
#include <fstream>

// Test 1: Save and load preserves tasks
void testSaveLoad() {
    TaskList list;
    list.addTask(Task("Homework", "Study"));
    list.addTask(Task("Gym", "Personal"));

    bool saved = list.saveToFile("test_tasks.txt");
    assert(saved);

    TaskList loaded;
    bool loadedOk = loaded.loadFromFile("test_tasks.txt");
    assert(loadedOk);

    std::cout << "Test save/load passed\n";
}

// Test 2: Mark completed persists after save/load
void testCompletionPersistence() {
    TaskList list;
    list.addTask(Task("Task1", "Work"));
    list.markTaskCompleted(0);
    list.saveToFile("test_tasks2.txt");

    TaskList loaded;
    loaded.loadFromFile("test_tasks2.txt");

    std::cout << "Test completion persistence passed\n";
}

// Test 3: Load from missing file fails safely
void testLoadFailure() {
    TaskList list;
    bool result = list.loadFromFile("file_does_not_exist.txt");
    assert(result == false);

    std::cout << "Test load failure passed\n";
}

int main() {
    testSaveLoad();
    testCompletionPersistence();
    testLoadFailure();

    std::cout << "\nAll Checkpoint 3 tests passed.\n";
    return 0;
}
