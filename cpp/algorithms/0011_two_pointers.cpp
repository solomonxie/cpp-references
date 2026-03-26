/**
 * Two Pointers Pattern
 * 
 * Commonly used on arrays and strings. It typically involves two pointers 
 * moving in one direction or towards each other.
 */
#include <iostream>
#include <vector>
#include <algorithm>

bool hasPairWithSum(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        if (sum < target) left++;
        else right--;
    }
    return false;
}

int main() {
    std::vector<int> data = {1, 2, 4, 6, 10};
    int target = 8;
    std::cout << "Has pair sum " << target << ": " << hasPairWithSum(data, target) << std::endl;
    return 0;
}
