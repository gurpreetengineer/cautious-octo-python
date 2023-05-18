#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  // Creating a hash map
  unordered_map<string, int> myMap;

  // Inserting key-value pairs
  myMap["apple"] = 3;
  myMap["banana"] = 2;
  myMap["orange"] = 5;

  // Retrieving values based on keys
  cout << "Number of apples: " << myMap["apple"] << endl;
  cout << "Number of bananas: " << myMap["banana"] << endl;
  cout << "Number of oranges: " << myMap["orange"] << endl;

  // Updating values based on keys
  myMap["apple"] = 10;
  cout << "Updated number of apples: " << myMap["apple"] << endl;

  // Deleting key-value pairs
  myMap.erase("banana");

  // Checking if a key exists in the hash map
  if (myMap.find("banana") == myMap.end())
  {
    cout << "Banana not found." << endl;
  }
  else
  {
    cout << "Number of bananas: " << myMap["banana"] << endl;
  }

  return 0;
}

/**
 * @brief Hash map operations explanation
 * Creating a hash map
 * Inserting key-value pairs
 * Retrieving values based on keys
 * Updating values based on keys
 * Deleting key-value pairs
 * Checking if a key exists in the hash map
 *
 * In this program, we utilize the unordered_map container from the C++ Standard Library, which implements a hash map.
 * First, we create a hash map called myMap using the unordered_map template.
 * We then insert key-value pairs using the square bracket operator ([]),
 * where the key is the string and the value is the corresponding integer.
 * We retrieve values from the hash map using the square bracket operator as well.
 * We update the value associated with a key by assigning a new value to it.
 * To delete a key-value pair, we use the erase function, providing the key as the argument.
 *
 * Finally, we demonstrate checking if a key exists in the hash map using the find function,
 * which returns an iterator pointing to the element if found or the end iterator if not found.
 *
 * Note: The order of elements in a hash map is not guaranteed as it depends on the hash function and internal implementation.
 *
 */
