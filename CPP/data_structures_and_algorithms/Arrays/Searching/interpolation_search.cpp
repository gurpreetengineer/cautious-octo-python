#include <iostream>

using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        int pos = lo + ((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]);
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 4;
    int index = interpolationSearch(arr, n, x);
    if (index != -1)
        cout << "Element " << x << " found at index " << index << endl;
    else
        cout << "Element " << x << " not found in the array" << endl;
    return 0;
}

/**
 * @brief interpolation search explanation
 * In this program, we first define the interpolationSearch function, which takes 
 * an array, 
 * its size, and 
 * the target value as input. 
 * 
 * This function performs the Interpolation Search algorithm on the array and returns the index of the target value if it is found, or -1 if it is not.
 * The main function initializes an array and the target value, and then calls the interpolationSearch function to find the target value in the array. 
 * If the target value is found, the program outputs the index of the target value. 
 * Otherwise, it outputs a message indicating that the target value was not found in the array.
 * 
 * Note that the Interpolation Search algorithm assumes that the array is sorted in ascending order. 
 * If the array is not sorted, the results of the search may be unpredictable.
 * 
 */
