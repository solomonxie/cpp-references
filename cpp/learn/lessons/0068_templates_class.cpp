// Lesson: Class templates (e.g. std::vector<T>-style)
// Compile: g++ -o 0068_templates_class 0068_templates_class.cpp

#include <iostream>
#include <string>

template <typename T>
class Box {
    T value_;
public:
    explicit Box(const T& v) : value_(v) {}
    T get() const { return value_; }
    void set(const T& v) { value_ = v; }
};

int main() {
    Box<int> bi(42);
    std::cout << "Box<int>: " << bi.get() << "\n";

    Box<double> bd(3.14);
    std::cout << "Box<double>: " << bd.get() << "\n";

    Box<std::string> bs("hello");
    std::cout << "Box<string>: " << bs.get() << "\n";
    return 0;
}
