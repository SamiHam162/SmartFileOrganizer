//
// Created by SamiH on 15/08/2024.
//

#include "ReportGenerator.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>

// Constructor: Initializes the ReportGenerator with a given report file name
ReportGenerator::ReportGenerator(const std::string& reportFileName) : reportFileName(reportFileName) {}

// Function to generate the report based on the results of the duplicate file check
void ReportGenerator::generateReport(const std::unordered_map<std::size_t, std::vector<std::string>>& duplicates) {
    // Open the report file for writing
    std::ofstream reportFile(reportFileName);

    if (!reportFile) {
        throw std::runtime_error("Could not open report file: " + reportFileName);
    }

    // Write the header for the report
    reportFile << "Duplicate File Report\n";
    reportFile << "=====================\n\n";

    // Write the timestamp for when the report was generated
    std::time_t currentTime = std::time(nullptr);
    reportFile << "Report generated on: " << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") << "\n\n";

    // Write details about duplicate files
    size_t duplicateCount = 0;
    for (const auto& [hash, paths] : duplicates) {
        if (paths.size() > 1) {
            reportFile << "Duplicate files for hash " << hash << ":\n";
            for (const auto& path : paths) {
                reportFile << " - " << path << "\n";
            }
            reportFile << "\n";
            duplicateCount += (paths.size() - 1);  // Count the duplicates (excluding the original)
        }
    }

    // Write a summary at the end of the report
    reportFile << "Summary:\n";
    reportFile << "--------\n";
    reportFile << "Total duplicates found: " << duplicateCount << "\n";
    reportFile << "Total unique files: " << (duplicates.size() - duplicateCount) << "\n";

    // Close the report file
    reportFile.close();

    std::cout << "Report generated successfully: " << reportFileName << std::endl;
}