// QuickSort algorithm using arrays in C++
#include <iostream>

// This function takes the last element as pivot, places the pivot element at its
// correct position in sorted array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right of pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);        // Index of smaller element
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QuickSort function using arrays
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Driver program to test above functions
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Given array is: \n";
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    std::cout << "Sorted array is: \n";
    printArray(arr, n);
    return 0;
}


/**
 * @brief explanation for quick sort
 * 
 * The above implementation uses the standard C++ library function std::swap to swap two elements of the array. 
 * 
 * This implementation has a time complexity of O(n log n) in the average case, and O(n^2) in the worst case. 
 * 
 * The space complexity of this implementation is O(1), as it only uses a constant amount of extra memory.
 * 
 */
