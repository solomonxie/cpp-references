# Build: cmake -S . -B build -DENABLE_GREETING=OFF && cmake --build build
# Run:   ./build/hello
#
# Step 10: option() defines a user-toggleable build flag, and configure_file()
# substitutes @VAR@ placeholders into a generated header.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_10 VERSION 1.2.0)

option(ENABLE_GREETING "Print a greeting on startup" ON)  # Step 10: `cmake -DENABLE_GREETING=OFF` flips this

configure_file(config.h.in config.h)  # Step 10: writes build/config.h from config.h.in

add_executable(hello main.cpp)
target_include_directories(hello PRIVATE ${CMAKE_CURRENT_BINARY_DIR})  # Step 10: config.h lives in the build dir
