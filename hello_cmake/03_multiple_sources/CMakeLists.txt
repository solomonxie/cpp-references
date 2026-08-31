# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 3: link multiple .cpp files into one executable.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_03)

add_executable(hello main.cpp greet.cpp)  # Step 3: list every source file the target needs
