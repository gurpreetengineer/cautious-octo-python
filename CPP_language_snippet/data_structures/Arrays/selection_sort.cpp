#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/**
 * @brief explanation of selection sort
 * 
 * In this implementation, we pass the array arr and its size n to the selectionSort() function. 
 * The function iterates over the array using two nested loops: the outer loop selects the minimum element
 * among the unsorted elements, and the inner loop compares each unsorted element to the current minimum element. 
 * When the minimum element is found, it is swapped with the element at the beginning of the unsorted sub-array. 
 * This process repeats until the entire array is sorted.
 * 
 * This implementation has a time complexity of O(n^2) in the worst case, which 
 * occurs when the array is already sorted in reverse order. 
 * 
 * However, it has a space complexity of O(1), which means it uses a constant amount of 
 * memory regardless of the size of the input array.
 * 
 */
