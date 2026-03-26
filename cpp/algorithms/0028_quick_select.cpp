/**
 * Quick Select
 * 
 * $O(n)$ average algorithm to find the $k$-th smallest element in 
 * an unordered list.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) std::swap(arr[i++], arr[j]);
    }
    std::swap(arr[i], arr[high]);
    return i;
}

int quickSelect(std::vector<int>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int index = partition(arr, low, high);
        if (index - low == k - 1) return arr[index];
        if (index - low > k - 1) return quickSelect(arr, low, index - 1, k);
        return quickSelect(arr, index + 1, high, k - index + low - 1);
    }
    return -1;
}

int main() {
    std::vector<int> data = {10, 4, 5, 8, 6, 11, 26};
    int k = 3;
    std::cout << k << "-th smallest element: " << quickSelect(data, 0, data.size() - 1, k) << std::endl;
    return 0;
}
