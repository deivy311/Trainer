# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Automatically set SUB_PROJECT_NAME to the current directory name
get_filename_component(SUB_PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Print the project name for debugging purposes
message(STATUS "SUB_PROJECT_NAME: ${SUB_PROJECT_NAME}")

# Include directories (adjust to your actual project structure)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Specify the source files for the project
set(SOURCES
    Assignment6_1_Section09.cpp   # main file
    Account.cpp
)

# Print the list of source files for debugging purposes
message(STATUS "SOURCES: ${SOURCES}")

# Add the executable target
add_executable(${SUB_PROJECT_NAME} ${SOURCES})

# Include directories for headers
target_include_directories(${SUB_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Linking libraries (optional: add libraries if needed, for now it's left empty)
target_link_libraries(${SUB_PROJECT_NAME}
    # gstreamer or other libraries can be added here if required
)
