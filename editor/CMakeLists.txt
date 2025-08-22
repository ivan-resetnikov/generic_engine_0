cmake_minimum_required(VERSION 3.0)

project(editor)

# Source
set(SRC_FILES
    editor.c
)

# Executable
add_executable(editor ${SRC_FILES})

# Link
