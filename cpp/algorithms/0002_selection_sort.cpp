/**
 * Selection Sort
 * 
 * $O(n^2)$ algorithm that divides the input list into two parts: 
 * a sorted sublist of items which is built up from left to right, 
 * and an unsorted sublist that occupies the rest of the list.
 */
#include <iostream>
#include <vector>
#include <algorithm>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

int main() {
    std::vector<int> data = {64, 25, 12, 22, 11};
    selectionSort(data);
    for (int x : data) std::cout << x << " ";
    return 0;
}
