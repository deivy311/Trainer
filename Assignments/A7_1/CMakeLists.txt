# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

project(A7)
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
    main.cpp        # main file
    Account.cpp     # implementation file for Account
    Checking.cpp    # implementation file for Checking
    Savings.cpp     # implementation file for Savings
    Transaction.cpp # implementation file for Transaction
)

# Specify the header files for the project (optional but helpful for IDEs)
set(HEADERS
    Account.h       # header file for Account
    Checking.h      # header file for Checking
    Savings.h       # header file for Savings
    Transaction.h   # header file for Transaction
)

# Print the list of source files for debugging purposes
message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "HEADERS: ${HEADERS}")

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

