#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
private:
  vector<int> table;
  int capacity;
  int size;

  int hashFunction1(int key)
  {
    return key % capacity;
  }

  int hashFunction2(int key)
  {
    return 1 + (key % (capacity - 1));
  }

public:
  HashTable(int capacity)
  {
    this->capacity = capacity;
    this->size = 0;
    table.resize(capacity, -1);
  }

  void insert(int key)
  {
    if (size == capacity)
    {
      cout << "Hash table is full. Cannot insert " << key << endl;
      return;
    }

    int index = hashFunction1(key);
    int offset = hashFunction2(key);
    int i = 0;

    while (table[index] != -1)
    {
      index = (index + offset) % capacity;
      i++;

      if (i == capacity)
      {
        cout << "Hash table is full. Cannot insert " << key << endl;
        return;
      }
    }

    table[index] = key;
    size++;
  }

  bool search(int key)
  {
    int index = hashFunction1(key);
    int offset = hashFunction2(key);
    int i = 0;

    while (table[index] != -1)
    {
      if (table[index] == key)
      {
        return true;
      }

      index = (index + offset) % capacity;
      i++;

      if (i == capacity)
      {
        break;
      }
    }

    return false;
  }

  void remove(int key)
  {
    int index = hashFunction1(key);
    int offset = hashFunction2(key);
    int i = 0;

    while (table[index] != -1)
    {
      if (table[index] == key)
      {
        table[index] = -1;
        size--;
        cout << "Key " << key << " removed from hash table" << endl;
        return;
      }

      index = (index + offset) % capacity;
      i++;

      if (i == capacity)
      {
        break;
      }
    }

    cout << "Key " << key << " not found in hash table" << endl;
  }

  void display()
  {
    cout << "Hash Table: ";
    for (int i = 0; i < capacity; i++)
    {
      if (table[i] != -1)
      {
        cout << table[i] << " ";
      }
      else
      {
        cout << "- ";
      }
    }
    cout << endl;
  }
};

int main()
{
  HashTable hashTable(10);

  hashTable.insert(5);
  hashTable.insert(15);
  hashTable.insert(25);
  hashTable.insert(35);
  hashTable.insert(45);
  hashTable.insert(55);
  hashTable.display();

  cout << "Search 35: " << (hashTable.search(35) ? "Found" : "Not Found") << endl;
  cout << "Search 50: " << (hashTable.search(50) ? "Found" : "Not Found") << endl;

  hashTable.remove(35);
  hashTable.display();

  return 0;
}

/**
 * @brief Open addressing using double hashing explanation
 *
 * In this program, the HashTable class implements a hash table with open addressing using double hashing collision handling technique.
 * The hash table is implemented using a vector, where each element represents a bucket in the hash table.
 * The insert function inserts a key into the hash table, and the search function searches for a key in the hash table.
 * The remove function removes a key from the hash table. The display function prints the current state of the hash table.
 *
 * The program demonstrates the usage of the hash table by inserting some keys, searching for keys, and removing keys.
 * The display function is used to print the state of the hash table after each operation.
 *
 * Note that the hash functions hashFunction1 and hashFunction2 are used to calculate the index and offset for double hashing, respectively.
 *
 */
