cmake_minimum_required(VERSION 3.10)

project(chemfiles-cli 
    DESCRIPTION "A simple chemistry file conversion CLI which wraps the chemfiles library"
    LANGUAGES C CXX
)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)

add_subdirectory(deps)
add_subdirectory(src)