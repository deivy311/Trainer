cmake_minimum_required(VERSION 3.10)

# Automatically set SUB_PROJECT_NAME to the current directory name
get_filename_component(SUB_PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Print the project name for debugging purposes
message(STATUS "SUB_PROJECT_NAME: ${SUB_PROJECT_NAME}")

# Finding pkg-config is a helper tool
find_package(PkgConfig REQUIRED)

# Including GStreamer and other relevant header files
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Set C++ standard to C++17 to use std::filesystem
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files (both .cpp and .c files) and header files
file(GLOB_RECURSE SOURCE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

file(GLOB_RECURSE HEADER_FILES_LOCAL 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

# Print the gathered source files for debugging
message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")

# Include the header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Print CMAKE_CURRENT_SOURCE_DIR for debugging purposes
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# Add the executable with the project name
add_executable(${SUB_PROJECT_NAME} ${SUB_PROJECT_NAME}.cpp ${SOURCE_FILES})

# Include directories for the target
target_include_directories(${SUB_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Linking the filesystem library (for C++17 `std::filesystem`)
target_link_libraries(${SUB_PROJECT_NAME} 
    stdc++fs  # Filesystem library
)

# Link the executable against any necessary GStreamer libraries (example)
# You can modify this if you use GStreamer libraries.
#pkg_check_modules(GST REQUIRED gstreamer-1.0)
#target_link_libraries(${SUB_PROJECT_NAME} ${GST_LIBRARIES})
