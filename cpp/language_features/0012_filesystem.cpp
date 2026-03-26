/**
 * 0012_filesystem.cpp
 * 
 * Demonstrates C++17 <filesystem> library for platform-independent
 * file and directory manipulation.
 */
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path p = "test_dir";

    // Create directory
    if (fs::create_directory(p)) {
        std::cout << "Directory created: " << p << std::endl;
    }

    // Check properties
    if (fs::exists(p)) {
        std::cout << "Path " << p << " exists." << std::endl;
        std::cout << "Is directory? " << fs::is_directory(p) << std::endl;
    }

    // List directory contents
    std::cout << "Contents of current path: " << std::endl;
    for (const auto& entry : fs::directory_iterator(".")) {
        std::cout << "  " << entry.path() << std::endl;
    }

    // Clean up
    fs::remove(p);
    std::cout << "Directory removed." << std::endl;

    return 0;
}
