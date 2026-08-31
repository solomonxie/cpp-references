# Build: cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build
# Run:   ./build/hello
#
# Step 8: CMAKE_BUILD_TYPE selects Debug/Release, and generator expressions
# apply flags conditionally per config.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_08)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)  # Step 8: default to Debug if the user didn't choose one
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_executable(hello main.cpp)
target_compile_options(hello PRIVATE
    $<$<CONFIG:Debug>:-g -O0 -DDEBUG_BUILD>   # Step 8: $<CONFIG:Debug> is a generator expression
    $<$<CONFIG:Release>:-O3>
)
