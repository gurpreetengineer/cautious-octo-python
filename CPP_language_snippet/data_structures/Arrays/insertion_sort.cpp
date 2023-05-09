#include <iostream>

using namespace std;

// Insertion sort function
void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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

  insertionSort(arr, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

/**
 * @brief explanation of insertion sort function
 * The insertionSort function takes an array arr of integers and its size n.
 * It uses a for loop to iterate over the array starting from the second element.
 * For each element, it picks the value as the key and checks if the elements before it are smaller.
 * If there are any smaller elements, it shifts them one position to the right until the correct position is found for the key.
 *
 * The time complexity of this implementation is O(n^2), which is the worst-case time complexity for insertion sort.
 *
 * However, in practice, it can be more efficient than other O(n^2) algorithms such as bubble sort or selection sort, especially for small arrays.
 *
 */
