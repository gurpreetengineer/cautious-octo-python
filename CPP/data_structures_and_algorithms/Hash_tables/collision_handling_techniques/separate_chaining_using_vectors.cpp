#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
private:
  int capacity;
  vector<vector<pair<int, int>>> table; // Vector of vectors to store key-value pairs

  int hashFunction(int key)
  {
    return key % capacity; // Simple modulus function as the hash function
  }

public:
  HashTable(int size)
  {
    capacity = size;
    table.resize(capacity); // Resize the table to the specified capacity
  }

  void insert(int key, int value)
  {
    int index = hashFunction(key);
    table[index].push_back({key, value}); // Append the key-value pair to the corresponding bucket
  }

  int get(int key)
  {
    int index = hashFunction(key);
    for (const auto &pair : table[index])
    {
      if (pair.first == key)
      {
        return pair.second; // Return the value if the key is found
      }
    }
    return -1; // Return -1 if the key is not found
  }
};

int main()
{
  HashTable hashTable(10);

  hashTable.insert(10, 100);
  hashTable.insert(20, 200);
  hashTable.insert(30, 300);

  cout << hashTable.get(10) << endl; // Output: 100
  cout << hashTable.get(20) << endl; // Output: 200
  cout << hashTable.get(30) << endl; // Output: 300
  cout << hashTable.get(40) << endl; // Output: -1 (Key not found)

  return 0;
}
