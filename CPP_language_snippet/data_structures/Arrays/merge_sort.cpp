#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    i = 0;
    j = 0;
    k = left;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
 
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);
 
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
 
    return 0;
}


/**
 * @brief explanation of merge sort
 * 
 * In this implementation, the merge function merges two subarrays of the input array arr. 
 * The mergeSort function recursively calls itself to sort the subarrays until there is only one element in each subarray. 
 * The merge function is then called to merge the subarrays back together in a sorted manner.
 * 
 * This implementation uses the divide-and-conquer strategy to sort the array, which 
 * has an average time complexity of O(n log n) and a space complexity of O(n).
 * 
 */
