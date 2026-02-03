// Lesson: Binary read/write, read/write
// Compile: g++ -o 0079_file_binary 0079_file_binary.cpp

#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    const char* path = "/tmp/0079_demo.bin";

    {
        std::ofstream out(path, std::ios::binary);
        if (out) {
            int arr[] = {10, 20, 30};
            out.write(reinterpret_cast<const char*>(arr), sizeof(arr));
        }
    }

    std::ifstream in(path, std::ios::binary);
    if (in) {
        int arr[3];
        in.read(reinterpret_cast<char*>(arr), sizeof(arr));
        std::cout << "read: " << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    }

    return 0;
}
