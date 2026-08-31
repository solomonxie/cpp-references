# Build: cmake -S . -B build && cmake --build build
# Test:  ctest --test-dir build --output-on-failure
#
# Step 12: enable_testing() + add_test() register a test executable with CTest.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_12)

add_executable(hello main.cpp)
add_executable(hello_test test.cpp)

enable_testing()                              # Step 12: turns on CTest for this project
add_test(NAME hello_test COMMAND hello_test)   # Step 12: `ctest` runs this executable, pass = exit code 0
