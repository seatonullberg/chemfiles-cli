add_executable(cf main.c)
target_link_libraries(cf argparse chemfiles)
target_include_directories(cf
    PRIVATE
        ${CMAKE_SOURCE_DIR}/deps/argparse/
        ${CMAKE_SOURCE_DIR}/deps/chemfiles/include/
)
install(TARGETS cf)