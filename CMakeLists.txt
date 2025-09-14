cmake_minimum_required(VERSION 3.10)

# Set the project name
project(library_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler options
if(WIN32)
    add_definitions(-DWIN32)
    set(RM_COMMAND "del /Q /S")
    set(MKDIR_COMMAND "mkdir")
    set(EXECUTABLE ${CMAKE_BINARY_DIR}/bin/library.exe)
    set(DATA_DIR_SEP "\\")
    set(RUN_COMMAND ${EXECUTABLE})
else()
    add_definitions(-DLINUX)
    set(RM_COMMAND "rm -rf")
    set(MKDIR_COMMAND "mkdir -p")
    set(EXECUTABLE ${CMAKE_BINARY_DIR}/bin/library)
    set(DATA_DIR_SEP "/")
    set(RUN_COMMAND ${EXECUTABLE})
endif()

# Directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(OBJ_DIR "${CMAKE_BINARY_DIR}/obj")
set(BIN_DIR "${CMAKE_BINARY_DIR}/bin")
set(DATA_DIR "${CMAKE_BINARY_DIR}/data")

# Include directories
include_directories(include)

# Collect source files
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# Create binary and object directories if they don't exist
file(MAKE_DIRECTORY ${OBJ_DIR})
file(MAKE_DIRECTORY ${BIN_DIR})
file(MAKE_DIRECTORY ${DATA_DIR})

# Add the executable
add_executable(library ${SRC_FILES})

