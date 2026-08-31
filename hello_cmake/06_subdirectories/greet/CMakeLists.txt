# Step 6: a child CMakeLists.txt, only visible once the parent add_subdirectory()s it.
add_library(greet STATIC src/greet.cpp)
target_include_directories(greet PUBLIC include)
