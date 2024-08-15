# Smart File Organizer

Smart File Organizer is a C++ application designed to help you organize files in a directory by their types and remove duplicate files. The application calculates file hashes to detect duplicates and generates a report of the actions taken.

## Features

- **File Organization**: Automatically organizes files in a directory into subdirectories based on file types (e.g., images, text files).
- **Duplicate Detection**: Detects and removes duplicate files using a hash-based comparison.
- **Report Generation**: Generates a detailed report of duplicate files that were removed and where files were moved.

## Getting Started

### Prerequisites

- **C++17 or later**
- **CMake** (for building the project)
- **Qt** (optional, if you plan to build the GUI version)

### Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/SamiHam162/SmartFileOrganizer.git
   cd SmartFileOrganizer
   
2. **Build the project:**

   ```bash
   mkdir build
   cd build
   cmake ..
   make

3. **Run the application:**

   ```bash
   ./SmartFileOrganizer

### Usage

1. **Command-Line Interface (CLI):**
   
   - After running the application, you will be prompted to select a directory.
   - The application will then organize files into subdirectories based on their file types.
   - Duplicate files will be identified and removed automatically.
   - A report named `DuplicateReport.txt` will be generated in the root directory.

2. **Graphical User Interface (GUI) (Optional):**

   - If you have built the GUI version with Qt, a graphical window will appear allowing you to:
     - Select a directory.
     - Check for duplicates.
     - Generate and view reports.

### Project Structure

- **src/**: Contains the main source code files.
  - `main.cpp`: Entry point for the application.
  - `FileOrganizer.cpp`: Handles file organization based on type.
  - `DuplicateChecker.cpp`: Contains logic for detecting and removing duplicates.
  - `ReportGenerator.cpp`: Generates the report for removed files.
  - `FileOrganizer.h`: Header for file organization logic.
  - `DuplicateChecker.h`: Header for duplicate checking logic.
  - `ReportGenerator.h`: Header for report generation.

- **include/**: Contains the header files.
  - `utilities.h`: Utilites functions for later usages.


- **tests/**: Contains test files.
  - `test_FileOrganizer.cpp`: Mock test cases for the file organizer module.

### Contributing

Contributions are welcome! Please feel free to submit a pull request or report any issues.

### Acknowledgments

- Thanks to the developers of Qt and other open-source tools used in this project.

### Contact

For any inquiries or support, please contact [SamiHam57@gmail.com](mailto:your-email@example.com).
