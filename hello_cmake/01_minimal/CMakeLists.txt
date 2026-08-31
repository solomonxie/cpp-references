# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 1: the smallest possible CMake project — one source file, one executable.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_01)

add_executable(hello main.cpp)
