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
