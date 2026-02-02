// Lesson: std::map, key-value, [] vs .at()
// Compile: g++ -o 0060_map 0060_map.cpp

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 35;

    std::cout << "Alice: " << ages["Alice"] << "\n";
    std::cout << "Bob: " << ages.at("Bob") << "\n";

    // [] inserts if missing; at() throws if missing
    std::cout << "ages[\"Dave\"] (inserts 0): " << ages["Dave"] << "\n";

    for (const auto& p : ages) {
        std::cout << p.first << " => " << p.second << "\n";
    }
    return 0;
}
