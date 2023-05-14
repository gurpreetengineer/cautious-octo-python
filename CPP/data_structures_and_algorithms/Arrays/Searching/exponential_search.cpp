#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x) {
        return 0;
    }
    int i = 1;
    while (i < n && arr[i] <= x) {
        i *= 2;
    }
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = exponentialSearch(arr, n, x);
    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index " << result << "." << endl;
    }
    return 0;
}

/**
 * @brief exponential search explanation
 * In this program, the exponentialSearch function takes 
 * an array, 
 * its size, and 
 * the element to search for as input parameters. 
 * 
 * The function starts by checking if the first element of the array is equal to the target element. 
 * If it is, the function returns the index of the first element. 
 * If it isn't, the function starts a loop that repeatedly doubles the value of the index i until either i is 
 * greater than the size of the array or the element at index i is greater than the target element.
 * After this loop, the function calls the binarySearch function with the range of the array from i/2 to min(i, n-1) as the search range. 
 * The binarySearch function is a recursive function that performs a binary search on the given range of the array. 
 * If the target element is found, the function returns its index. 
 * If it isn't found, the function returns -1. 
 * 
 * Finally, the main function calls the exponentialSearch function with the given input and prints the result.
 * 
 */
