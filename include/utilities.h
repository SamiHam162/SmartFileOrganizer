//
// Created by SamiH on 15/08/2024.
//

#ifndef SMARTFILEORGANIZER_UTILITIES_H
#define SMARTFILEORGANIZER_UTILITIES_H

#include <string>
#include <filesystem>

namespace utils {
    std::string getExtension(const std::string& fileName) {
        return std::filesystem::path(fileName).extension().string();
    }
}

#endif //SMARTFILEORGANIZER_UTILITIES_H
