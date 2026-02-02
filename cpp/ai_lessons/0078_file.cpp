// Lesson: <fstream>, ifstream/ofstream, open, read/write lines
// Compile: g++ -o 0078_file 0078_file.cpp

#include <iostream>
#include <fstream>
#include <string>

int main() {
    const char* path = "/tmp/0078_demo.txt";

    {
        std::ofstream out(path);
        if (out) {
            out << "line one\n";
            out << "line two\n";
        }
    }

    std::ifstream in(path);
    std::string line;
    while (std::getline(in, line)) {
        std::cout << "read: " << line << "\n";
    }

    return 0;
}
