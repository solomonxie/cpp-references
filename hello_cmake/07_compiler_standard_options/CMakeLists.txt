# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 7: require a C++ standard per-target and turn on warnings per-target,
# instead of relying on compiler defaults.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_07 CXX)

add_executable(hello main.cpp)

target_compile_features(hello PRIVATE cxx_std_17)     # Step 7: require C++17 for this target only
target_compile_options(hello PRIVATE -Wall -Wextra)   # Step 7: enable warnings for this target only
