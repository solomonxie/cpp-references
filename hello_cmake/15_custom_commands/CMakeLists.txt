# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 15: add_custom_command() generates a file at build time (codegen);
# add_custom_target() names that step so other targets can depend on it.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_15)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/build_info.h
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/generate_build_info.cmake ${CMAKE_CURRENT_BINARY_DIR}/build_info.h
    DEPENDS generate_build_info.cmake
    COMMENT "Generating build_info.h"
)  # Step 15: runs before anything that depends on build_info.h. Writing the file via a
   # `cmake -P` script (file(WRITE ...)) sidesteps shell-quoting differences between
   # generators, instead of piping `cmake -E echo` through `>`.

add_custom_target(generate_build_info DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/build_info.h)  # Step 15: a named, buildable target

add_executable(hello main.cpp)
add_dependencies(hello generate_build_info)   # Step 15: force codegen to run before compiling hello
target_include_directories(hello PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
