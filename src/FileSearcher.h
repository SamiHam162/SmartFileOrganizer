//
// Created by SamiH on 15/08/2024.
//

#ifndef SMARTFILEORGANIZER_FILESEARCHER_H
#define SMARTFILEORGANIZER_FILESEARCHER_H

#include <string>

class FileSearcher {
public:
    FileSearcher(const std::string& directory);
    void search(const std::string& keyword);

private:
    std::string directoryPath;
    void searchFiles(const std::string& keyword);
};

#endif //SMARTFILEORGANIZER_FILESEARCHER_H
