/**
 * Binary Search
 * 
 * $O(\log n)$ algorithm to find the position of a target value within 
 * a sorted array. It compares the target value to the middle element 
 * of the array.
 */
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 4;
    std::cout << "Index of " << target << ": " << binarySearch(data, target) << std::endl;
    return 0;
}
