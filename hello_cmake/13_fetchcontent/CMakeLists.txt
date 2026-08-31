# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 13: FetchContent downloads and configures an external dependency
# (here, the fmt library) at `cmake` configure time. Needs network access
# the first time it's configured.
cmake_minimum_required(VERSION 3.14)
project(hello_cmake_13)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        10.2.1
)
FetchContent_MakeAvailable(fmt)  # Step 13: fetch, then add_subdirectory() it automatically

add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE fmt::fmt)
