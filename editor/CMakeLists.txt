cmake_minimum_required(VERSION 3.5)

project(editor)

# Source
set(SRC_FILES
    editor.c
)

# Executable
add_executable(editor ${SRC_FILES})

# Link
set(LINK_TARGETS )

if (WIN32)
    # Windows-specific linking targets
elseif(APPLE)
    # MacOS-specific linking targets
elseif(UNIX)
    # UNIX-specific linking targets
    list(APPEND LINK_TARGETS X11)
endif()

target_link_libraries(editor PRIVATE ${LINK_TARGETS})
