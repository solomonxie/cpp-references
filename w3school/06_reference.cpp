#include <iostream>
using namespace std;


// "&" speak as "Address Of"
int main() {
    string food = "Pizza";
    // Speak as "Address of _meal_ is _food_"
    string &meal = food;
    cout << meal << "\n"; // >> Pizza
    // ouput memory address: speak as "address of _meal_"
    cout << &meal << "\n";  // >> 0x16b1e6610
    cout << &food << "\n";  // >> 0x16b1e6610
    return 0;
}
