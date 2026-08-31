# Build:   cmake -S . -B build && cmake --build build
# Install: cmake --install build --prefix ./out
#
# Step 11: install() rules describe what `cmake --install` copies and where.
cmake_minimum_required(VERSION 3.10)
project(hello_cmake_11)

add_executable(hello main.cpp)

install(TARGETS hello DESTINATION bin)              # Step 11: -> <prefix>/bin/hello
install(FILES README.txt DESTINATION share/hello)   # Step 11: -> <prefix>/share/hello/README.txt
