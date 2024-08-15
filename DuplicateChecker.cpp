//
// Created by SamiH on 15/08/2024.
//

#include "DuplicateChecker.h"
#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <functional>

namespace fs = std::filesystem;

// Constructor for the DuplicateChecker class
// Initializes the directory path where files will be checked for duplicates
DuplicateChecker::DuplicateChecker(const std::string& directory) : directoryPath(directory) {}


// This function generates a hash for the contents of a file using std::hash
std::size_t DuplicateChecker::generateFileHash(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    std::string fileContents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Use std::hash to generate a hash from the file contents
    std::hash<std::string> hasher;
    return hasher(fileContents);
}

// This function checks for duplicate files in the specified directory
// It compares files by generating and comparing their hash values
// If duplicates are found, they are removed from the file system
void DuplicateChecker::checkForDuplicates() {
    std::unordered_map<std::size_t, std::vector<std::string>> hashToFilePaths;

    // Iterate through each file in the directory
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            try {
                // Generate the hash for the current file
                std::size_t fileHash = generateFileHash(entry.path().string());

                // Store the file path under its hash in the map
                hashToFilePaths[fileHash].push_back(entry.path().string());
            } catch (const std::exception& e) {
                std::cerr << "Error processing file: " << e.what() << std::endl;
            }
        }
    }

    // Report and remove duplicate files
    for (const auto& [hash, paths] : hashToFilePaths) {
        if (paths.size() > 1) {
            std::cout << "Duplicate files found for hash " << hash << ":\n";
            for (size_t i = 1; i < paths.size(); ++i) {
                std::cout << " - Removing " << paths[i] << std::endl;
                fs::remove(paths[i]);  // Remove the duplicate file
            }
            std::cout << std::endl;
        }
    }
}