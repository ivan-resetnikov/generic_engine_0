cmake_minimum_required(VERSION 3.0)

project(runtime)

# Source
set(SRC_FILES
    runtime.c
)

# Executable
add_executable(runtime ${SRC_FILES})

# Link
