#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i; // return index of the key element
        }
    }
    return -1; // key element not found
}

int main() {
    int arr[] = {3, 6, 1, 8, 4, 9, 2, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    int index = linearSearch(arr, n, key);
    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

/**
 * @brief linear search explanation
 * In this program, the linearSearch function takes three arguments: 
 * the array arr, 
 * its size n, and 
 * the key element key that we want to search for. 
 * 
 * The function loops through each element of the array using a for loop, checking if the current element is equal to the key element. 
 * If a match is found, the function returns the index of that element. 
 * If no match is found, the function returns -1.
 * 
 * In the main function, we create an example array arr and define the key element key that we want to search for. 
 * We call the linearSearch function with these arguments and store the returned index in the index variable. 
 * Finally, we check if the index is not equal to -1, indicating that the key element was found in the array, and print a message with the index. 
 * 
 * If the index is -1, we print a message indicating that the element was not found.
 * 
 * This program has a time complexity of O(n), where n is the size of the array. 
 * This means that the time required to search for an element in the array increases linearly with the size of the array.
 * 
 */
