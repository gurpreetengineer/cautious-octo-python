#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> findUniqueElements(const vector<int> &arr)
{
  map<int, int> uniqueMap;
  vector<int> uniqueElements;

  // Insert elements into the map, duplicates will be automatically removed
  for (int i = 0; i < arr.size(); i++)
  {
    uniqueMap[arr[i]] = i;
  }

  // Retrieve unique elements from the map and store them in a vector
  for (const auto &pair : uniqueMap)
  {
    uniqueElements.push_back(pair.first);
  }

  return uniqueElements;
}

int main()
{
  vector<int> arr = {5, 2, 7, 2, 9, 5, 7, 2, 1};

  cout << "Original array: ";
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  vector<int> uniqueElements = findUniqueElements(arr);

  cout << "Unique elements: ";
  for (int num : uniqueElements)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

/**
 * @brief Finding uniques elements in an array using maps explanation
 *
 * In this program, the findUniqueElements function takes an array as input and uses a map to store the unique elements.
 * Duplicates are automatically removed because a map allows only one entry per key. 
 * The function iterates over the array and inserts each element as a key into the map, 
 * with the corresponding value being the index of the element.
 * Then, it retrieves the unique elements from the map and stores them in a vector.
 * The main function demonstrates the usage of the findUniqueElements function 
 * with a sample array and prints the original array and the unique elements found.
 * 
 * In the example given, the original array is {5, 2, 7, 2, 9, 5, 7, 2, 1}. 
 * After finding the unique elements using the map, the program prints the original array and the unique elements {5, 2, 7, 9, 1}.
 * 
 * This program provides an efficient solution to find the unique elements in an array using a map, 
 * with a time complexity of O(n), where n is the size of the input array.
 *
 */
