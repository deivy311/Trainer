# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Assignment1)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the src folder to the list of include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Find required packages (OpenCV, Eigen, etc.)
find_package(OpenCV REQUIRED)
#find_package(Eigen3 REQUIRED)

# Source files
set(SOURCES
   Assignment1.cpp
   math.cpp
    #src/other_source.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries (OpenCV, Eigen, etc.)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    #Eigen3::Eigen
)

# Output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

