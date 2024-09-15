# cmake_minimum_required(VERSION 3.10)
# set(SUB_PROJECT_NAME "Point_0")
# Automatically set SUB_PROJECT_NAME to the current directory name
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(SUB_PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Print the project name for debugging purposes
message(STATUS "SUB_PROJECT_NAME: ${SUB_PROJECT_NAME}")
#finding pkg-config is a helper tool
find_package(PkgConfig REQUIRED)

#including GStreamer header files directory
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)


# Add source files
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
file(GLOB_RECURSE HEADER_FILES_LOCAL ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

#print SOURCE_FILES
message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")

# Add source files

# Add header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#print CMAKE_CURRENT_SOURCE_DIR
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
#building target executable
# add_executable(${SUB_PROJECT_NAME} point_0.cpp ${SOURCE_FILES_LOCAL} ${HEADER_FILES_LOCAL})
add_executable(${SUB_PROJECT_NAME} ${SUB_PROJECT_NAME}.cpp  ${SOURCE_FILES})
# link the exe against the libraries
# target_sources(${SUB_PROJECT_NAME} PRIVATE ${SOURCE_FILES_LOCAL})

target_include_directories(${SUB_PROJECT_NAME}
    PUBLIC
    ${HEADER_FILES_LOCAL}
    ${CMAKE_CURRENT_BINARY_DIR}
)
# #linking Gstreamer library with target executable
target_link_libraries(${SUB_PROJECT_NAME} 
        )
