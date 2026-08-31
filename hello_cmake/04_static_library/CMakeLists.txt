# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 4: build greet.cpp into a static library, then link it into the executable.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_04)

add_library(greet STATIC greet.cpp)          # Step 4: a reusable static library target
add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE greet)   # Step 4: link the library into the executable
