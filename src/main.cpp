//
// Created by SamiH on 15/08/2024.
//
#include "DuplicateChecker.h"
#include "ReportGenerator.h"
#include "FileOrganizer.h"

int main() {
    // Specify the directory to check for duplicates and organize files
    std::string directoryPath = "/path/to/your/directory";

    // Step 1: Check for duplicates and remove them
    DuplicateChecker checker(directoryPath);
    checker.checkForDuplicates();

    // Get the duplicate file information
    auto duplicates = checker.getDuplicates();

    // Step 2: Generate a report of the duplicates
    ReportGenerator reportGenerator("DuplicateReport.txt");
    reportGenerator.generateReport(duplicates);

    // Step 3: Organize the remaining files in the directory (e.g., by file type)
    FileOrganizer organizer(directoryPath);
    organizer.organizeFiles();

    return 0;
}