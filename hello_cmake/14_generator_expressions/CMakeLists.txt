# Build: cmake -S . -B build && cmake --build build
# Run:   ./build/hello
#
# Step 14: more generator-expression forms — BUILD_INTERFACE/INSTALL_INTERFACE
# for include paths, and $<TARGET_FILE:...> expanding to a real output path.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_14)

add_library(greet STATIC greet.cpp)
target_include_directories(greet PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # Step 14: only applies while building in-tree
    $<INSTALL_INTERFACE:include>                             # Step 14: only applies to installed/exported consumers
)

add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE greet)

target_compile_definitions(hello PRIVATE
    $<$<CONFIG:Debug>:VERBOSE_LOGGING>  # Step 14: config-conditional define, revisited from Step 8
)

add_custom_command(TARGET hello POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Built: $<TARGET_FILE:hello>"  # Step 14: genexpr expands at build time
)
