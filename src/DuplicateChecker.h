//
// Created by SamiH on 15/08/2024.
//

#ifndef SMARTFILEORGANIZER_DUPLICATECHECKER_H
#define SMARTFILEORGANIZER_DUPLICATECHECKER_H

#include <string>
#include <vector>

class DuplicateChecker {
public:
    // Constructor: Initializes the DuplicateChecker with the directory path
    DuplicateChecker(const std::string& directory);

    // Function to check for and remove duplicate files in the specified directory
    void checkForDuplicates();

private:
    // Function to generate a hash for the contents of a file
    std::size_t generateFileHash(const std::string& filePath);

    // Directory path where the files will be checked for duplicates
    std::string directoryPath;
};

#endif //SMARTFILEORGANIZER_DUPLICATECHECKER_H
