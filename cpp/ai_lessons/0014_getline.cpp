// Lesson: std::getline(), whitespace, cin vs getline
// Compile: g++ -o 0014_getline 0014_getline.cpp

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a line (getline): ";
    std::string line;
    std::getline(std::cin, line);   // reads until newline, keeps spaces
    std::cout << "You entered: \"" << line << "\"\n";

    std::cout << "Enter a word (cin >>): ";
    std::string word;
    std::cin >> word;   // stops at first whitespace
    std::cout << "You entered: \"" << word << "\"\n";

    // After cin >>, newline may remain; getline then reads empty line.
    std::cin.ignore(1000, '\n');  // skip rest of line
    std::cout << "Enter another line: ";
    std::getline(std::cin, line);
    std::cout << "Line: \"" << line << "\"\n";
    return 0;
}
