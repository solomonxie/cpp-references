/**
 * Monotonic Stack Pattern
 * 
 * Stack that maintains elements in increasing or decreasing order. 
 * Often used to find the "next greater element".
 */
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> res(n, -1);
    std::stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            res[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int main() {
    std::vector<int> data = {2, 1, 2, 4, 3};
    std::vector<int> res = nextGreaterElement(data);
    std::cout << "Next Greater Elements: ";
    for (int x : res) std::cout << x << " ";
    return 0;
}
