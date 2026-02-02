// Lesson: cout, cin, >>, <<, basic formatting
// Compile: g++ -o 0013_cout_cin 0013_cout_cin.cpp

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;   // reads until whitespace

    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old.\n";
    std::cout << "Chained output: " << 1 << " " << 2 << " " << 3 << "\n";
    return 0;
}
