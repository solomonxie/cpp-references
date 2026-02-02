// Lesson: JSON parse/serialize (requires nlohmann/json or similar)
// This example uses only standard library; for real JSON add a header-only
// library like https://github.com/nlohmann/json (single include: json.hpp)
// Compile (with nlohmann/json): g++ -o 0080_json 0080_json.cpp -I path/to/json/include -std=c++11
// Without library: compile and run to see placeholder output.

#include <iostream>
#include <string>

// Placeholder: without nlohmann/json we just print a message.
// With nlohmann/json you would:
//   #include <nlohmann/json.hpp>
//   using json = nlohmann::json;
//   json j = {{"name", "Alice"}, {"age", 30}};
//   std::string s = j.dump();
//   json j2 = json::parse(s);

int main() {
    std::cout << "JSON lesson: use a library (e.g. nlohmann/json) for parse/serialize.\n";
    std::cout << "Example: json j = {{\"name\", \"Alice\"}, {\"age\", 30}}; std::string s = j.dump();\n";
    return 0;
}
