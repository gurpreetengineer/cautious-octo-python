#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  // Creating a hash table
  unordered_map<string, int> hashTable;

  // Inserting key-value pairs
  hashTable["apple"] = 5;
  hashTable["banana"] = 10;
  hashTable["orange"] = 7;

  // Retrieving values based on keys
  cout << "Value of 'apple': " << hashTable["apple"] << endl;
  cout << "Value of 'banana': " << hashTable["banana"] << endl;
  cout << "Value of 'orange': " << hashTable["orange"] << endl;

  // Updating values based on keys
  hashTable["apple"] = 8;
  cout << "Updated value of 'apple': " << hashTable["apple"] << endl;

  // Deleting key-value pairs
  hashTable.erase("banana");

  // Checking if a key exists in the hash table
  string key = "banana";
  if (hashTable.find(key) != hashTable.end())
  {
    cout << "'" << key << "' exists in the hash table." << endl;
  }
  else
  {
    cout << "'" << key << "' does not exist in the hash table." << endl;
  }

  return 0;
}

/**
 * @brief Basic hash table operations explanation
 * Creating a hash table
 * Inserting key-value pairs
 * Retrieving values based on keys
 * Updating values based on keys
 * Deleting key-value pairs
 * Checking if a key exists in the hash table
 *
 * In this program, we use the unordered_map container from the C++ Standard Library to implement a hash table.
 * We create a hash table named hashTable that maps strings to integers.
 * We insert key-value pairs using the bracket notation (hashTable["key"] = value),
 * retrieve values using the same bracket notation,
 * update values by assigning a new value to the corresponding key, and
 * delete key-value pairs using the erase function.
 * To check if a key exists in the hash table, we use the find function to search for the key and compare it against hashTable.end().
 *
 * Please note that the unordered_map container in C++ implements a hash table using a hash function for fast key-value retrieval.
 * It provides average constant-time complexity for inserting, retrieving, and deleting elements.
 *
 */
