cmake_minimum_required(VERSION 3.10)

project(Scacchi)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "clang++")

# Set build type to Debug (use Debug or Release)
set(CMAKE_BUILD_TYPE Debug)

# Add the executable with source files
file(GLOB PEZZI "src/Pezzi/*.cpp")
file(GLOB SOURCES "src/*.cpp")
add_executable(Scacchi ${PEZZI} ${SOURCES})

# Include directories for headers
include_directories(include include/Pezzi)

# Optionally, link external libraries (e.g., Boost or pthread)
# target_link_libraries(MyProject Boost::Boost)
