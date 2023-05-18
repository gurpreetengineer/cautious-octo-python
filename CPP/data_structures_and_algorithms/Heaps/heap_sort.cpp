#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap in descending order
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {9, 2, 7, 1, 5, 10, 3, 6, 4, 8};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/**
 * @brief heap sort explanation
 * 
 * In this program, the heapify function is used to maintain the heap property of a subtree rooted at index i. 
 * The heapSort function first builds a max heap by calling heapify for each non-leaf node. 
 * Then, it repeatedly extracts the maximum element from the heap by swapping it with the last element, 
 * reducing the heap size, and calling heapify to restore the heap property. 
 * Finally, the sorted array is printed.
 * 
 * The program demonstrates the usage of heap sort by sorting an array of integers in ascending order. 
 * The original array and the sorted array are printed for verification.
 * 
 * Heap sort has a time complexity of O(n log n) and is an efficient sorting algorithm for large datasets.
 * 
 */
