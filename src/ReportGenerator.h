//
// Created by SamiH on 15/08/2024.
//

#ifndef SMARTFILEORGANIZER_REPORTGENERATOR_H
#define SMARTFILEORGANIZER_REPORTGENERATOR_H

#include <string>
#include <unordered_map>
#include <vector>

class ReportGenerator {
public:
    // Constructor: Initializes the ReportGenerator with a given report file name
    ReportGenerator(const std::string& reportFileName);

    // Function to generate the report based on the results of the duplicate file check
    void generateReport(const std::unordered_map<std::size_t, std::vector<std::string>>& duplicates);

private:
    // Name of the report file where the report will be generated
    std::string reportFileName;
};

#endif //SMARTFILEORGANIZER_REPORTGENERATOR_H
