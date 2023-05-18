#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  // Creating a hash set
  unordered_set<int> hashSet;

  // Inserting elements
  hashSet.insert(10);
  hashSet.insert(20);
  hashSet.insert(30);
  hashSet.insert(40);
  hashSet.insert(50);

  // Checking if an element exists
  int key = 30;
  if (hashSet.count(key) > 0)
  {
    cout << "Element " << key << " exists in the hash set." << endl;
  }
  else
  {
    cout << "Element " << key << " does not exist in the hash set." << endl;
  }

  // Removing elements
  hashSet.erase(20);
  hashSet.erase(40);

  // Checking if an element exists after removal
  key = 40;
  if (hashSet.count(key) > 0)
  {
    cout << "Element " << key << " exists in the hash set." << endl;
  }
  else
  {
    cout << "Element " << key << " does not exist in the hash set." << endl;
  }

  return 0;
}

/**
 * @brief Hash set operations explanation
 * Creating a hash set
 * Inserting elements
 * Checking if an element exists
 * Removing elements
 *
 * In this program, we utilize the unordered_set container from the C++ Standard Library to implement a hash set.
 * We start by creating an empty hash set using unordered_set<int> hashSet.
 *
 * Next, we insert elements into the hash set using the insert() function. In this example, we insert the integers 10, 20, 30, 40, and 50.
 *
 * To check if an element exists in the hash set, we use the count() function.
 * If the count is greater than 0, it means the element exists in the hash set. Otherwise, it does not exist.
 *
 * We demonstrate the removal of elements from the hash set using the erase() function.
 * In this case, we remove elements 20 and 40 from the hash set.
 *
 * Finally, we again check if an element exists in the hash set after the removal.
 * In this example, we check if 40 exists in the hash set and print the corresponding message.
 *
 * Feel free to modify the program and the elements according to your requirements.
 *
 */
