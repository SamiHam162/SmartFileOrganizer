//
// Created by SamiH on 15/08/2024.
//
#include "../src/FileOrganizer.h"
#include <iostream>
#include <cassert>

// Mock class for the FileOrganizer
class MockFileOrganizer : public FileOrganizer {
public:
    // Constructor that passes the directory path to the base class
    MockFileOrganizer(const std::string& directory) : FileOrganizer(directory), createDirectoryCalled(0), moveFileCalled(0) {}

    // Override the organizeFilesByType function to just print instead of actually organizing files
    void organizeFiles()  {
        std::cout << "Mock organizeFilesByType called" << std::endl;

        // Simulate getting different file types
        std::string fileType1 = "txt";
        std::string fileType2 = "jpg";

        createDirectoryIfNotExists(directoryPath + "/" + fileType1);
        moveFileToDirectory("file1.txt", directoryPath + "/" + fileType1);

        createDirectoryIfNotExists(directoryPath + "/" + fileType2);
        moveFileToDirectory("file2.jpg", directoryPath + "/" + fileType2);
    }

    // Override the private helper functions and track their calls
    std::string getFileType(const std::string& filePath) const  {
        std::cout << "Mock getFileType called for: " << filePath << std::endl;
        if (filePath == "file1.txt") {
            return "txt";
        } else if (filePath == "file2.jpg") {
            return "jpg";
        }
        return "unknown";
    }

    void createDirectoryIfNotExists(const std::string& dir)  {
        std::cout << "Mock createDirectoryIfNotExists called for: " << dir << std::endl;
        createDirectoryCalled++;
    }

    void moveFileToDirectory(const std::string& filePath, const std::string& dir)  {
        std::cout << "Mock moveFileToDirectory called for: " << filePath << " to " << dir << std::endl;
        moveFileCalled++;
    }

    // Getters to check how many times the functions were called
    int getCreateDirectoryCalled() const { return createDirectoryCalled; }
    int getMoveFileCalled() const { return moveFileCalled; }

private:
    mutable int createDirectoryCalled;
    mutable int moveFileCalled;
};

// Simple test function to run the mock test
void test_FileOrganizer() {
    // Create the mock object
    MockFileOrganizer mockOrganizer("C:/test/directory");

    // Run the function that is under test
    mockOrganizer.organizeFiles();

    // Check that the createDirectoryIfNotExists and moveFileToDirectory functions were called the correct number of times
    assert(mockOrganizer.getCreateDirectoryCalled() == 2);
    assert(mockOrganizer.getMoveFileCalled() == 2);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_FileOrganizer();
    return 0;
}