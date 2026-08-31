# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 5: move the header into its own include/ dir and expose it via
# target_include_directories instead of relying on same-folder #include lookup.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_05)

add_library(greet STATIC src/greet.cpp)
target_include_directories(greet PUBLIC include)  # Step 5: PUBLIC = consumers of `greet` inherit this path too

add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE greet)
