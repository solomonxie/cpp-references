// Lesson: Stack vs heap, lifetime, scope
// Compile: g++ -o 0053_stack_heap 0053_stack_heap.cpp

#include <iostream>

int main() {
    int stack_var = 42;   // on stack: lifetime = this block
    std::cout << "stack_var = " << stack_var << "\n";

    int* heap_var = new int(100);  // on heap: lives until delete
    std::cout << "*heap_var = " << *heap_var << "\n";
    delete heap_var;  // must free
    // heap_var is now dangling; don't use

    {
        int local = 10;  // stack: destroyed at end of block
        std::cout << "local = " << local << "\n";
    }
    // local no longer exists
    return 0;
}
