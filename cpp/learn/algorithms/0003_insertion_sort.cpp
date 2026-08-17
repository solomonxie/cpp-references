/**
 * Insertion Sort
 * 
 * Simple $O(n^2)$ sorting algorithm that builds the final sorted array 
 * one item at a time. It is much less efficient on large lists than 
 * more advanced algorithms.
 */
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6};
    insertionSort(data);
    for (int x : data) std::cout << x << " ";
    return 0;
}
