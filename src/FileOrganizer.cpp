//
// Created by SamiH on 15/08/2024.
//

#include "FileOrganizer.h"
#include <filesystem>
#include <iostream>
#include <map>

namespace fs = std::filesystem;

FileOrganizer::FileOrganizer(const std::string& directory) : directoryPath(directory) {}

void FileOrganizer::organizeFiles() {
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

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            std::string category;
            if (extensionToCategory.find(extension) != extensionToCategory.end()) {
                category = extensionToCategory[extension];
            } else {
                category = "Others";
            }
            moveFile(entry.path().string(), category);
        }
    }
}

void FileOrganizer::createCategoryFolders() {
    // Create folders based on categories if they don't exist
    std::map<std::string, std::string> categories = {
            {"Images", directoryPath + "/Images"},
            {"Videos", directoryPath + "/Videos"},
            {"Audio", directoryPath + "/Audio"},
            {"Documents", directoryPath + "/Documents"},
            {"TextFiles", directoryPath + "/TextFiles"},
            {"SourceCode", directoryPath + "/SourceCode"},
            {"Others", directoryPath + "/Others"}
    };

    for (const auto& category : categories) {
        if (!fs::exists(category.second)) {
            fs::create_directory(category.second);
        }
    }
}

void FileOrganizer::moveFile(const std::string& filePath, const std::string& category) {
    // Move the file to the appropriate category folder
    std::string destinationDir = directoryPath + "/" + category;

    if (!fs::exists(destinationDir)) {
        fs::create_directory(destinationDir);
    }

    std::string fileName = fs::path(filePath).filename().string();
    std::string destinationPath = destinationDir + "/" + fileName;

    try {
        fs::rename(filePath, destinationPath);
        std::cout << "Moved: " << filePath << " -> " << destinationPath << std::endl;
    } catch (fs::filesystem_error& e) {
        std::cerr << "Error moving file: " << e.what() << std::endl;
    }
}