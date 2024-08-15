//
// Created by SamiH on 15/08/2024.
//

#ifndef SMARTFILEORGANIZER_FILEORGANIZER_H
#define SMARTFILEORGANIZER_FILEORGANIZER_H

#include <string>

class FileOrganizer {
public:
    explicit FileOrganizer(const std::string& directory);
    void organizeFiles();

private:
    std::string directoryPath;
    void createCategoryFolders();
    void moveFile(const std::string& filePath, const std::string& category);
};

#endif //SMARTFILEORGANIZER_FILEORGANIZER_H
