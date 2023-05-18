#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
private:
  int capacity;                    // Size of the hash table
  vector<pair<int, string>> table; // Hash table storing key-value pairs
  vector<bool> filled;             // Keeps track of filled slots in the hash table

  int hashFunction(int key)
  {
    return key % capacity; // Simple hash function using modulo operator
  }

  int quadraticProbe(int key, int i)
  {
    return (hashFunction(key) + i * i) % capacity; // Quadratic probing
  }

public:
  HashTable(int size)
  {
    capacity = size;
    table.resize(capacity);
    filled.resize(capacity, false);
  }

  void insert(int key, const string &value)
  {
    int index = hashFunction(key);
    int i = 0;

    while (filled[index])
    {
      index = quadraticProbe(key, ++i);
    }

    table[index] = make_pair(key, value);
    filled[index] = true;
  }

  string search(int key)
  {
    int index = hashFunction(key);
    int i = 0;

    while (filled[index])
    {
      if (table[index].first == key)
      {
        return table[index].second;
      }
      index = quadraticProbe(key, ++i);
    }

    return "Key not found.";
  }
};

int main()
{
  HashTable hashTable(10);

  // Inserting key-value pairs
  hashTable.insert(5, "Apple");
  hashTable.insert(7, "Banana");
  hashTable.insert(11, "Orange");
  hashTable.insert(18, "Mango");

  // Searching for values using keys
  cout << "5: " << hashTable.search(5) << endl;
  cout << "7: " << hashTable.search(7) << endl;
  cout << "11: " << hashTable.search(11) << endl;
  cout << "18: " << hashTable.search(18) << endl;
  cout << "10: " << hashTable.search(10) << endl;

  return 0;
}

/**
 * @brief Open addressing using quadratic probing explanation
 *
 * In this program, the HashTable class implements a hash table with open addressing using quadratic probing.
 * The hashFunction method computes the hash value of a key by taking the modulo of the key with the capacity of the hash table.
 * The quadraticProbe method performs the quadratic probing calculation to handle collisions.
 *
 * The insert method inserts a key-value pair into the hash table by finding the appropriate index using quadratic probing.
 * If the index is already filled, it continues probing until an empty slot is found.
 * The search method searches for a key in the hash table by following the same quadratic probing process and
 * @returns the corresponding value if found.
 *
 * In the main function, a HashTable object is created with a capacity of 10.
 * Key-value pairs are inserted into the hash table, and then searches are performed using the keys to retrieve the values.
 *
 * Note that this implementation assumes the keys are integers and the values are strings for simplicity.
 * You can modify the program to handle different key-value types as needed.
 *
 */
