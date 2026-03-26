/**
 * Prefix Sum Pattern
 * 
 * Used for range sum queries in $O(1)$ after $O(n)$ preprocessing.
 */
#include <iostream>
#include <vector>

class PrefixSum {
    std::vector<int> prefix;
public:
    PrefixSum(const std::vector<int>& arr) {
        prefix.resize(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
    }
    int rangeSum(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    PrefixSum ps(data);
    std::cout << "Sum [1, 3]: " << ps.rangeSum(1, 3) << " (expected 2+3+4=9)" << std::endl;
    return 0;
}
