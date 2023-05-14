#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    int index = binarySearch(arr, n, target);
    if (index == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << index << endl;
    }
    return 0;
}


/**
 * @brief binary search explanation
 * In this program, the binarySearch function takes three arguments: 
 * the array to be searched, 
 * the size of the array, and 
 * the target element to be found. 
 * 
 * The function uses the binary search algorithm to search for the target element in the array and returns the index of the element if found, or -1 if not found.
 * 
 * In the main function, an array is defined and the binarySearch function is called with the array, size, and target element as arguments. 
 * The program then prints a message indicating whether the element was found or not.
 * 
 * This implementation of binary search has a time complexity of O(log n), which makes it very efficient for searching large arrays.
 * 
 */
