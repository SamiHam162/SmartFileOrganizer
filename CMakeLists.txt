cmake_minimum_required(VERSION 3.25)
project(SmartFileOrganizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SmartFileOrganizer
        src/main.cpp src/FileOrganizer.cpp src/FileOrganizer.h DuplicateChecker.cpp DuplicateChecker.h)
