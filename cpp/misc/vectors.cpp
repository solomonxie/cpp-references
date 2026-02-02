#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    std::cout << "starting..." << std::endl;
    std::vector<int> nums = {1,3,9,8,4,3,2,6};
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
