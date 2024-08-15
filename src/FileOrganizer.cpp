//
// Created by SamiH on 15/08/2024.
//

#include "FileOrganizer.h"
#include <filesystem>
#include <iostream>
#include <map>

namespace fs = std::filesystem;


// Constructor for the FileOrganizer class
// Initializes the directoryPath with the provided directory
FileOrganizer::FileOrganizer(const std::string& directory) : directoryPath(directory) {}

// This function organizes files in the specified directory
// It categorizes files based on their extensions and moves them to corresponding folders
void FileOrganizer::organizeFiles() {
    // Map to associate file extensions with their respective categories
    std::map<std::string, std::string> extensionToCategory = {
            {".jpg", "Images"},
            {".jpeg", "Images"},
            {".png", "Images"},
            {".bmp", "Images"},
            {".gif", "Images"},
            {".mp4", "Videos"},
            {".mkv", "Videos"},
            {".mp3", "Audio"},
            {".wav", "Audio"},
            {".pdf", "Documents"},
            {".doc", "Documents"},
            {".docx", "Documents"},
            {".txt", "TextFiles"},
            {".cpp", "SourceCode"},
            {".h", "SourceCode"},
            {".py", "SourceCode"},
            {".java", "SourceCode"},
            // Add more extensions as needed
    };

    // Iterate through each file in the directory
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            // Get the file extension
            std::string extension = entry.path().extension().string();
            std::string category;

            // Determine the category based on the extension
            if (extensionToCategory.find(extension) != extensionToCategory.end()) {
                category = extensionToCategory[extension];
            } else {
                category = "Others"; // Default category for unknown extensions
            }

            // Move the file to the appropriate category folder
            moveFile(entry.path().string(), category);
        }
    }
}

// This function creates category folders in the specified directory
// It checks if the folders already exist, and creates them if they don't
void FileOrganizer::createCategoryFolders() {
    // Map associating category names with folder paths
    std::map<std::string, std::string> categories = {
            {"Images", directoryPath + "/Images"},
            {"Videos", directoryPath + "/Videos"},
            {"Audio", directoryPath + "/Audio"},
            {"Documents", directoryPath + "/Documents"},
            {"TextFiles", directoryPath + "/TextFiles"},
            {"SourceCode", directoryPath + "/SourceCode"},
            {"Others", directoryPath + "/Others"}
    };

    // Create each category folder if it doesn't already exist
    for (const auto& category : categories) {
        if (!fs::exists(category.second)) {
            fs::create_directory(category.second);
        }
    }
}

// This function moves a file to the specified category folder
// If the destination folder doesn't exist, it creates it
void FileOrganizer::moveFile(const std::string& filePath, const std::string& category) {
    // Construct the destination directory path
    std::string destinationDir = directoryPath + "/" + category;

    // Create the destination directory if it doesn't exist
    if (!fs::exists(destinationDir)) {
        fs::create_directory(destinationDir);
    }

    // Extract the file name from the file path
    std::string fileName = fs::path(filePath).filename().string();
    // Construct the full path to the destination file
    std::string destinationPath = destinationDir + "/" + fileName;

    try {
        // Move the file to the destination path
        fs::rename(filePath, destinationPath);
        std::cout << "Moved: " << filePath << " -> " << destinationPath << std::endl;
    } catch (fs::filesystem_error& e) {
        // Handle any errors that occur during the file move operation
        std::cerr << "Error moving file: " << e.what() << std::endl;
    }
}