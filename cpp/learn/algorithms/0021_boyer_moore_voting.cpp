/**
 * Boyer-Moore Voting Algorithm
 * 
 * Finds the majority element (element that appears more than n/2 times) 
 * in $O(n)$ time and $O(1)$ space.
 */
#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    std::vector<int> data = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "Majority Element: " << majorityElement(data) << std::endl;
    return 0;
}
