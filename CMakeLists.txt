#0) Configure project directory settings
cmake_minimum_required(VERSION 3.31)
project(SingletonDB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#1) Add the test executable
add_executable(db_main src/db.cpp src/main.cpp include/db.h)

#2) Include directories for the test target
target_include_directories(db_main PRIVATE ${PROJECT_SOURCE_DIR}/include)

#3) Enable testing
enable_testing()
