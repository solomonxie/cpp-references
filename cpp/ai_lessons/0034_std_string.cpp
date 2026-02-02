// Lesson: std::string, concatenation, .size(), indexing
// Compile: g++ -o 0034_std_string 0034_std_string.cpp

#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello";
    std::string s2 = " world";
    std::string s3 = s1 + s2;
    std::cout << "s1 + s2 = \"" << s3 << "\"\n";

    std::cout << "s3.size() = " << s3.size() << "\n";
    std::cout << "s3[0] = '" << s3[0] << "' s3[6] = '" << s3[6] << "'\n";

    s1 += "!";  // append
    std::cout << "s1 += \"!\" -> \"" << s1 << "\"\n";

    std::string s4(5, 'x');  // "xxxxx"
    std::cout << "std::string(5, 'x') = \"" << s4 << "\"\n";
    return 0;
}
