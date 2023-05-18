#include <iostream>
#include <vector>

enum class EntryStatus
{
  Empty,
  Occupied,
  Deleted
};

class HashTable
{
private:
  int bucketSize;
  std::vector<int> table;
  std::vector<EntryStatus> status;

  int hashFunction(int key)
  {
    return key % bucketSize;
  }

  int linearProbe(int key, int i)
  {
    return (hashFunction(key) + i) % bucketSize;
  }

public:
  HashTable(int size)
  {
    bucketSize = size;
    table.resize(bucketSize, 0);
    status.resize(bucketSize, EntryStatus::Empty);
  }

  void insert(int key)
  {
    int index = hashFunction(key);
    int i = 0;
    while (status[index] == EntryStatus::Occupied)
    {
      index = linearProbe(key, ++i);
    }
    table[index] = key;
    status[index] = EntryStatus::Occupied;
  }

  bool search(int key)
  {
    int index = hashFunction(key);
    int i = 0;
    while (status[index] != EntryStatus::Empty)
    {
      if (status[index] == EntryStatus::Occupied && table[index] == key)
      {
        return true;
      }
      index = linearProbe(key, ++i);
    }
    return false;
  }

  void remove(int key)
  {
    int index = hashFunction(key);
    int i = 0;
    while (status[index] != EntryStatus::Empty)
    {
      if (status[index] == EntryStatus::Occupied && table[index] == key)
      {
        status[index] = EntryStatus::Deleted;
        return;
      }
      index = linearProbe(key, ++i);
    }
  }
};

int main()
{
  HashTable hashTable(10);

  // Inserting element    hashTable.insert(5);
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
