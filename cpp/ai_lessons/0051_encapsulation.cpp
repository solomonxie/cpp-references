// Lesson: Getters/setters, design rationale
// Compile: g++ -o 0051_encapsulation 0051_encapsulation.cpp

#include <iostream>
#include <string>

class Temperature {
private:
    double celsius_;  // internal representation

public:
    double getCelsius() const { return celsius_; }
    void setCelsius(double c) {
        if (c >= -273.15) celsius_ = c;  // validate
    }
    double getFahrenheit() const {
        return celsius_ * 9.0 / 5.0 + 32.0;
    }
    void setFahrenheit(double f) {
        setCelsius((f - 32.0) * 5.0 / 9.0);
    }
};

int main() {
    Temperature t;
    t.setCelsius(100);
    std::cout << "100 C = " << t.getFahrenheit() << " F\n";
    t.setFahrenheit(32);
    std::cout << "32 F = " << t.getCelsius() << " C\n";
    return 0;
}
