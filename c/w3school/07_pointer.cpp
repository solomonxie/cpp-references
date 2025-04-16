#include <iostream>
using namespace std;

// "*" -> speak as "Value Of"
int main() {
    string food = "Pizza";
    // Pointer: speak as "Value of _ptr_ is Reference of _food_"
    string* ptr = &food;
    // output value: speak as "point to _ptr_"
    cout << "*ptr: " << *ptr << "\n";  // >> Pizza
    // output mem address:
    cout << "ptr: " << ptr << "\n";  // >> 0x16b1e6610
    // output mem address (same with pointer):
    cout << "&food: " << &food << "\n";
    cout << "(ptr == &food): " << (ptr == &food) << "\n";
    // pointer saves the "mem address" in a differet "mem address":
    cout << "&ptr: " << &ptr << "\n";
    cout << "*ptr: " << *ptr << "\n";

    // Change value
    food = "Burger";
    cout << "changed to: " << *ptr << "\n";
    return 0;
}
