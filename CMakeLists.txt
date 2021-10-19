cmake_minimum_required(VERSION 3.10)

project(chemfiles-cli 
    DESCRIPTION "A simple chemistry file conversion CLI which wraps the chemfiles library"
    LANGUAGES C CXX
)

add_subdirectory(deps)
add_subdirectory(src)