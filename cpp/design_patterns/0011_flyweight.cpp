/**
 * Flyweight Pattern
 * 
 * Lets you fit more objects into the available amount of RAM by sharing
 * common parts of state between multiple objects instead of keeping all
 * of the data in each object.
 */
#include <iostream>
#include <string>
#include <map>
#include <memory>

// Flyweight: Shared state (Intrinsic)
class TreeType {
    std::string name, color, texture;
public:
    TreeType(std::string n, std::string c, std::string t) : name(n), color(c), texture(t) {}
    void draw(int x, int y) {
        std::cout << "Drawing tree " << name << " [" << color << "] at (" << x << "," << y << ")" << std::endl;
    }
};

// Flyweight Factory
class TreeFactory {
    static std::map<std::string, std::shared_ptr<TreeType>> treeTypes;
public:
    static std::shared_ptr<TreeType> getTreeType(std::string name, std::string color, std::string texture) {
        std::string key = name + color + texture;
        if (treeTypes.find(key) == treeTypes.end()) {
            treeTypes[key] = std::make_shared<TreeType>(name, color, texture);
        }
        return treeTypes[key];
    }
};
std::map<std::string, std::shared_ptr<TreeType>> TreeFactory::treeTypes;

// Context: Unique state (Extrinsic)
class Tree {
    int x, y;
    std::shared_ptr<TreeType> type;
public:
    Tree(int x, int y, std::shared_ptr<TreeType> t) : x(x), y(y), type(t) {}
    void draw() { type->draw(x, y); }
};

int main() {
    auto type1 = TreeFactory::getTreeType("Oak", "Green", "Rough");
    auto type2 = TreeFactory::getTreeType("Pine", "Dark Green", "Smooth");

    Tree t1(10, 20, type1);
    Tree t2(15, 25, type1); // Shares type1
    Tree t3(50, 50, type2);

    t1.draw();
    t2.draw();
    t3.draw();

    return 0;
}
