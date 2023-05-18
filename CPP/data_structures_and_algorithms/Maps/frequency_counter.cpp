#include <iostream>
#include <map>
#include <vector>

using namespace std;

void countFrequency(const vector<int> &arr)
{
  map<int, int> frequencyMap;

  // Count the frequency of each element
  for (int num : arr)
  {
    frequencyMap[num]++;
  }

  // Print the frequency of each element
  for (const auto &pair : frequencyMap)
  {
    cout << pair.first << ": " << pair.second << endl;
  }
}

int main()
{
  vector<int> arr = {2, 5, 3, 2, 5, 3, 1, 7, 9, 1, 2, 5};

  cout << "Frequency Counter" << endl;
  cout << "Array: ";
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  cout << "Element frequencies:" << endl;
  countFrequency(arr);

  return 0;
}

/**
 * @brief Frequency counter explanation using maps
 *
 * In this program, the countFrequency function takes an array (arr) as input.
 * It creates a map (frequencyMap) where the elements of the array serve as keys and their frequencies as values.
 * The function iterates over each element of the array, increments the frequency in the map, and
 * finally prints the frequency of each element.
 *
 * In the example given, the program counts the frequency of elements in the array
 * {2, 5, 3, 2, 5, 3, 1, 7, 9, 1, 2, 5}. It then displays the element frequencies using the countFrequency function.
 *
 * The output of the program will be:
 * * Frequency Counter
 * * Array: 2 5 3 2 5 3 1 7 9 1 2 5
 * * Element frequencies:
 * * 1: 2
 * * 2: 3
 * * 3: 2
 * * 5: 3
 * * 7: 1
 * * 9: 1
 *
 * This demonstrates an efficient way to count the frequency of each element in an array using a map in C++.
 *
 */
