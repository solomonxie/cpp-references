// Lesson: struct, members, initialization
// Compile: g++ -o 0044_struct 0044_struct.cpp

#include <iostream>
#include <string>

struct Point {
    double x;
    double y;
};

struct Person {
    std::string name;
    int age;
};

int main() {
    Point p1 = {1.0, 2.0};
    std::cout << "p1.x = " << p1.x << " p1.y = " << p1.y << "\n";

    Person p2;
    p2.name = "Alice";
    p2.age = 30;
    std::cout << p2.name << " is " << p2.age << "\n";

    Person p3 = {"Bob", 25};  // aggregate initialization
    std::cout << p3.name << " is " << p3.age << "\n";
    return 0;
}
