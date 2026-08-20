/**
 * Strategy Pattern
 * 
 * Lets you define a family of algorithms, put each of them into a separate
 * class, and make their objects interchangeable.
 */
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Strategy {
public:
    virtual ~Strategy() {}
    virtual std::string doAlgorithm(const std::vector<std::string>& data) const = 0;
};

class Context {
    std::unique_ptr<Strategy> strategy;
public:
    Context(std::unique_ptr<Strategy> s = nullptr) : strategy(std::move(s)) {}
    void setStrategy(std::unique_ptr<Strategy> s) { strategy = std::move(s); }
    void doSomeBusinessLogic() const {
        std::vector<std::string> data = {"a", "e", "c", "b", "d"};
        std::cout << "Context: Sorting data using the strategy\n";
        std::string result = strategy->doAlgorithm(data);
        std::cout << result << std::endl;
    }
};

class ConcreteStrategyA : public Strategy {
public:
    std::string doAlgorithm(const std::vector<std::string>& data) const override {
        std::string result;
        std::vector<std::string> sorted_data = data;
        std::sort(sorted_data.begin(), sorted_data.end());
        for (const std::string& element : sorted_data) result += element;
        return result;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    std::string doAlgorithm(const std::vector<std::string>& data) const override {
        std::string result;
        std::vector<std::string> sorted_data = data;
        std::sort(sorted_data.begin(), sorted_data.end(), std::greater<std::string>());
        for (const std::string& element : sorted_data) result += element;
        return result;
    }
};

int main() {
    Context context(std::make_unique<ConcreteStrategyA>());
    context.doSomeBusinessLogic();

    std::cout << "\nContext: Strategy is set to reverse sorting.\n";
    context.setStrategy(std::make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();

    return 0;
}
