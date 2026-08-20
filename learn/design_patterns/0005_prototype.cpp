/**
 * Prototype Pattern
 * 
 * Specifies the kinds of objects to create using a prototypical instance,
 * and creates new objects by copying this prototype.
 */
#include <iostream>
#include <memory>
#include <string>

class Shape {
public:
    virtual ~Shape() {}
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }
    void draw() const override {
        std::cout << "Drawing Circle with radius: " << radius << std::endl;
    }
};

class Rectangle : public Shape {
private:
    float width, height;
public:
    Rectangle(float w, float h) : width(w), height(h) {}
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }
    void draw() const override {
        std::cout << "Drawing Rectangle: " << width << "x" << height << std::endl;
    }
};

int main() {
    std::unique_ptr<Shape> circlePrototype = std::make_unique<Circle>(5.0f);
    std::unique_ptr<Shape> rectPrototype = std::make_unique<Rectangle>(10.0f, 20.0f);

    auto c1 = circlePrototype->clone();
    auto r1 = rectPrototype->clone();

    c1->draw();
    r1->draw();

    return 0;
}
