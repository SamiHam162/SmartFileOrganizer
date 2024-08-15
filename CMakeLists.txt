cmake_minimum_required(VERSION 3.25)
project(SmartFileOrganizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SmartFileOrganizer
        src/main.cpp src/FileOrganizer.cpp src/FileOrganizer.h src/DuplicateChecker.cpp src/DuplicateChecker.h src/FileSearcher.cpp src/FileSearcher.h src/FileSearcher.h src/ReportGenerator.cpp src/ReportGenerator.h include/utilities.h)
