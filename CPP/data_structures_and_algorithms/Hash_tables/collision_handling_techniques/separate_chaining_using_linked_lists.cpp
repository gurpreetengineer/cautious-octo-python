#include <iostream>
#include <list>
#include <vector>

class HashTable
{
private:
  int bucketSize;
  std::vector<std::list<int>> table;

  int hashFunction(int key)
  {
    return key % bucketSize;
  }

public:
  HashTable(int size)
  {
    bucketSize = size;
    table.resize(bucketSize);
  }

  void insert(int key)
  {
    int index = hashFunction(key);
    table[index].push_back(key);
  }

  bool search(int key)
  {
    int index = hashFunction(key);
    for (int value : table[index])
    {
      if (value == key)
      {
        return true;
      }
    }
    return false;
  }

  void remove(int key)
  {
    int index = hashFunction(key);
    table[index].remove(key);
  }
};

int main()
{
  HashTable hashTable(10);

  // Inserting elements
  hashTable.insert(5);
  hashTable.insert(15);
  hashTable.insert(25);
  hashTable.insert(35);

  // Searching elements
  std::cout << "Search 15: " << (hashTable.search(15) ? "Found" : "Not Found") << std::endl;
  std::cout << "Search 50: " << (hashTable.search(50) ? "Found" : "Not Found") << std::endl;

  // Removing elements
  hashTable.remove(15);
  std::cout << "Search 15: " << (hashTable.search(15) ? "Found" : "Not Found") << std::endl;

  return 0;
}
