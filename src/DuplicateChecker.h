//
// Created by SamiH on 15/08/2024.
//

#ifndef SMARTFILEORGANIZER_DUPLICATECHECKER_H
#define SMARTFILEORGANIZER_DUPLICATECHECKER_H

#include <string>
#include <vector>
#include <unordered_map>

class DuplicateChecker {
public:
    // Constructor: Initializes the DuplicateChecker with the directory path
    DuplicateChecker(const std::string& directory);

    // Function to check for and remove duplicate files in the specified directory
    void checkForDuplicates();

    // Function to get the map of duplicates
    std::unordered_map<std::size_t, std::vector<std::string>> getDuplicates() const;

private:
    // Function to generate a hash for the contents of a file
    std::size_t generateFileHash(const std::string& filePath);

    // Directory path where the files will be checked for duplicates
    std::string directoryPath;

    // Map to store duplicate files based on their hash
    std::unordered_map<std::size_t, std::vector<std::string>> removedFiles;
};

#endif //SMARTFILEORGANIZER_DUPLICATECHECKER_H
