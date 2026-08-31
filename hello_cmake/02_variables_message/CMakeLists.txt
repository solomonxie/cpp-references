# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 2: adds set() variables and message() for build-time output.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_02)

set(APP_NAME hello)                        # Step 2: a normal CMake variable
set(GREETING "Hello from CMake")           # Step 2: a string variable

message(STATUS "Configuring ${APP_NAME}")  # Step 2: printed while running `cmake -S . -B build`

add_executable(${APP_NAME} main.cpp)
target_compile_definitions(${APP_NAME} PRIVATE GREETING="${GREETING}")  # Step 2: pass the variable into C++ as a macro
