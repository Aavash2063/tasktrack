cmake_minimum_required(VERSION 3.10)

project(TaskTrack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Task.cpp
    src/TaskList.cpp
)

# Create executable
add_executable(tasktrack ${SOURCES})
enable_testing()

add_executable(test_checkpoint3
    tests/test_checkpoint3.cpp
    src/Task.cpp
    src/TaskList.cpp
)

add_test(NAME Checkpoint3Tests COMMAND test_checkpoint3)
