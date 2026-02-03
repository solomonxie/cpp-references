// Lesson: Manual allocation patterns, common pitfalls (double-free, leak)
// Compile: g++ -o 0058_memory_operation 0058_memory_operation.cpp

#include <iostream>

int main() {
    // Pitfall 1: leak (forget delete)
    int* p = new int(42);
    // ... use p ...
    delete p;  // must delete when done
    p = nullptr;  // avoid use-after-free

    // Pitfall 2: double-free
    int* q = new int(10);
    delete q;
    // delete q;  // undefined behavior
    q = nullptr;  // safe to delete nullptr (no-op)

    // Pitfall 3: use after free
    int* r = new int(7);
    delete r;
    // *r = 0;  // undefined behavior

    // Prefer smart pointers (see 0055, 0056, 0057) to avoid these.
    std::cout << "Manual memory: always pair new with delete, avoid double-free and use-after-free.\n";
    return 0;
}
