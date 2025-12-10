#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include "TaskList.h"

/**
 * FileHandler is responsible for saving and loading Task data
 * to and from a simple text file format.
 */
class FileHandler {
private:
    std::string filename;

public:
    // Constructors
    FileHandler();
    FileHandler(const std::string& dataFile);

    // Getters / setters
    std::string getFilename() const;
    void setFilename(const std::string& dataFile);

    // File operations
    bool save(const TaskList& list) const;
    bool load(TaskList& list) const;
};

#endif // FILEHANDLER_H
