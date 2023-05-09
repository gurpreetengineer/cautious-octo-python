#include <iostream>

using namespace std;

// Bubble sort function
void bubbleSort(int arr[], int n)
{
  bool swapped;
  for (int i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
    {
      break;
    }
  }
}

// Test program
int main()
{
  int arr[] = {5, 1, 9, 3, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  bubbleSort(arr, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}


/**
 * @brief explanation of bubble sort function
 * This program defines a bubbleSort function that takes an integer array and its size as input and sorts the array in ascending order using the bubble sort algorithm.

 * The bubble sort algorithm works by repeatedly swapping adjacent elements in the array if they are in the wrong order, until the entire array is sorted. 
 * In the bubbleSort function, we use two nested loops to iterate over all pairs of adjacent elements in the array. 
 * If a pair of adjacent elements is in the wrong order, we swap them using the swap function from the <algorithm> header. 
 * The outer loop iterates n-1 times because the largest element will have already bubbled up to the end of the array after n-1 iterations. 
 * The inner loop iterates n-i-1 times because the last i elements of the array will already be sorted after i iterations of the outer loop.
 * 
 * In the main function, we define an integer array arr and its size n, and call the bubbleSort function to sort the array. We then print the original and sorted arrays using a for loop.
 * 
 */
