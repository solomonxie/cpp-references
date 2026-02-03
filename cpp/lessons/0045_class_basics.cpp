// Lesson: class, public/private, member functions
// Compile: g++ -o 0045_class_basics 0045_class_basics.cpp

#include <iostream>
#include <string>

class Rectangle {
public:
    double width;
    double height;

    double area() const {
        return width * height;
    }

    void set(double w, double h) {
        width = w;
        height = h;
    }
};

class Box {
private:
    double w_, h_, d_;

public:
    void set(double w, double h, double d) {
        w_ = w;
        h_ = h;
        d_ = d;
    }
    double volume() const { return w_ * h_ * d_; }
};

int main() {
    Rectangle r;
    r.width = 3;
    r.height = 4;
    std::cout << "Rectangle area = " << r.area() << "\n";

    Box b;
    b.set(2, 3, 4);
    std::cout << "Box volume = " << b.volume() << "\n";
    return 0;
}
