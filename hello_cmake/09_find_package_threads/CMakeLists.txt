# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 9: find_package() locates a system-provided dependency (here, threads),
# and its imported target is linked like any other library.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_09)

find_package(Threads REQUIRED)  # Step 9: sets up the platform's pthread/Win32-thread library

add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE Threads::Threads)  # Step 9: imported target, not a raw -lpthread
