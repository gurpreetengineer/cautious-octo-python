#include <iostream>
#include <cmath>

using namespace std;

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n)-1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) {
            return -1;
        }
    }
    if (arr[prev] == x) {
        return prev;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    int index = jumpSearch(arr, n, x);
    if (index == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << index << endl;
    }
    return 0;
}

/**
 * @brief jump search explanation
 * In this implementation, the jumpSearch function takes 
 * an array arr, 
 * the size of the array n, and 
 * the target element x as input, and 
 * @returns the index of the target element in the array.
 * The algorithm starts by setting the jump step size to the square root of the size of the array, and iterating through the array in steps of the jump size until either 
 * the end of the array is reached or an element greater than or equal to the target element is found. 
 * At this point, the algorithm performs a linear search in the block of elements between the previous step and the current step to find the target element.
 * If the target element is found, the index of the element is returned. 
 * Otherwise, the function returns -1 to indicate that the element was not found in the array.
 * 
 * This implementation has a time complexity of O(sqrt(n)), which is more efficient than linear search for large arrays.
 * 
 */
