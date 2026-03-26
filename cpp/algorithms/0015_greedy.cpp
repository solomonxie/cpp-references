/**
 * Greedy Pattern
 * 
 * Makes the locally optimal choice at each stage with the hope of 
 * finding a global optimum.
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight, value;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (auto& item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;
    std::cout << "Max value in knapsack: " << fractionalKnapsack(W, items) << std::endl;
    return 0;
}
