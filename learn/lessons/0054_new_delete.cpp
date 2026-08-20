// Lesson: new/delete, new[]/delete[]
// Compile: g++ -o 0054_new_delete 0054_new_delete.cpp

#include <iostream>

int main() {
    // Single object
    int* p = new int(42);
    std::cout << "*p = " << *p << "\n";
    delete p;
    p = nullptr;

    // Array
    int* arr = new int[5]{10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
    delete[] arr;  // use delete[] for new[]
    arr = nullptr;

    // Mismatch: new[] with delete (undefined) or new with delete[] (undefined)
    // Always pair new with delete, new[] with delete[]
    return 0;
}
