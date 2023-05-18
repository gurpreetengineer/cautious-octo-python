#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int>& arr) {
    int n = arr.size();

    // Build the heap from the last non-leaf node to the root
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printArray(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);

    buildHeap(arr);

    cout << "Heapified array: ";
    printArray(arr);

    return 0;
}

/**
 * @brief heapify algorithm for converting an array into a heap structure explanation
 * 
 * In this program, the heapify function takes an array, its size n, and an index i as parameters. 
 * It assumes that the subtrees rooted at the left and right children of i are already heaps and ensures that the subtree rooted at i also becomes a heap. 
 * 
 * The buildHeap function initializes the heap by calling heapify on each non-leaf node of the array, starting from the last non-leaf node. 
 * Finally, the printArray function is used to print the elements of the array.
 * 
 * In the example given, the original array is {12, 11, 13, 5, 6, 7}.
 * After performing heapify, the array becomes a heap structure. 
 * The program prints the original array and the heapified array to demonstrate the heapify algorithm in action.
 * 
 */
