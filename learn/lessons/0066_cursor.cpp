// Lesson: Cursor-style iteration (index-based cursor)
// Compile: g++ -o 0066_cursor 0066_cursor.cpp

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};
    size_t cursor = 0;  // index as "cursor"

    while (cursor < v.size()) {
        std::cout << "cursor=" << cursor << " value=" << v[cursor] << "\n";
        ++cursor;
    }

    // Reset cursor and advance by 2
    cursor = 0;
    while (cursor < v.size()) {
        std::cout << v[cursor] << " ";
        cursor += 2;
    }
    std::cout << "\n";
    return 0;
}
