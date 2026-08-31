# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 6: split greet into its own subdirectory with its own CMakeLists.txt,
# pulled in with add_subdirectory().
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_06)

add_subdirectory(greet)  # Step 6: processes greet/CMakeLists.txt, defines the `greet` target

add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE greet)
