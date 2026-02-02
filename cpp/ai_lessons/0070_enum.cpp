// Lesson: enum, enum class (scoped enum)
// Compile: g++ -o 0070_enum 0070_enum.cpp -std=c++11

#include <iostream>

enum Color { Red, Green, Blue };  // unscoped: Red, Green, Blue in global scope

enum class Direction { North, South, East, West };  // scoped

int main() {
    Color c = Red;
    std::cout << "Color Red = " << static_cast<int>(c) << "\n";

    Direction d = Direction::North;
    std::cout << "Direction::North = " << static_cast<int>(d) << "\n";

    if (c == Red) std::cout << "c is Red\n";
    if (d == Direction::South) { } else std::cout << "d is not South\n";

    // enum class avoids name collisions and is type-safe
    return 0;
}
