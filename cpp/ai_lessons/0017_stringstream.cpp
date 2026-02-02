// Lesson: std::istringstream / std::ostringstream
// Compile: g++ -o 0017_stringstream 0017_stringstream.cpp

#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Parse from string (istringstream)
    std::string data = "42 3.14 hello";
    std::istringstream iss(data);
    int i;
    double d;
    std::string s;
    iss >> i >> d >> s;
    std::cout << "Parsed: i=" << i << " d=" << d << " s=" << s << "\n";

    // Build string (ostringstream)
    std::ostringstream oss;
    oss << "Number: " << 100 << " and " << 200;
    std::string result = oss.str();
    std::cout << "Built string: " << result << "\n";
    return 0;
}
