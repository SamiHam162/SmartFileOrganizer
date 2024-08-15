//
// Created by SamiH on 15/08/2024.
//

#include "FileSearcher.h"


#include "FileSearcher.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

FileSearcher::FileSearcher(const std::string& directory) : directoryPath(directory) {}

void FileSearcher::search(const std::string& keyword) {
    searchFiles(keyword);
}

void FileSearcher::searchFiles(const std::string& keyword) {
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            if (entry.path().filename().string().find(keyword) != std::string::npos) {
                std::cout << "Found: " << entry.path() << std::endl;
            }
        }
    }
}