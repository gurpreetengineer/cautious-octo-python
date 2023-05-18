#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  // Create a dictionary using a map
  map<string, string> dictionary;

  // Add words and their definitions to the dictionary
  dictionary["apple"] = "a fruit that grows on trees";
  dictionary["banana"] = "a long curved fruit with a yellow skin";
  dictionary["car"] = "a road vehicle with four wheels";

  // Look up words in the dictionary
  string word;
  cout << "Enter a word to look up in the dictionary: ";
  cin >> word;

  // Find the word in the dictionary
  auto iter = dictionary.find(word);
  if (iter != dictionary.end())
  {
    cout << "Definition: " << iter->second << endl;
  }
  else
  {
    cout << "Word not found in the dictionary." << endl;
  }

  return 0;
}

/**
 * @brief Dictionary explanation using maps
 *
 * Dictionary: Implementing a dictionary using a map data structure, where words are stored along with their definitions,
 * and users can look up words to retrieve their meanings efficiently.
 *
 * In this program, we use the map container from the Standard Template Library (STL) to represent the dictionary.
 * Words are stored as keys, and their definitions are stored as corresponding values in the map.
 * The program allows users to enter a word and retrieves its definition from the dictionary.
 *
 * In the example given, we create a dictionary with a few words and their definitions.
 * The program prompts the user to enter a word, searches for the word in the dictionary using the find function, and
 * prints the corresponding definition if found.
 * If the word is not found, it displays a message indicating that the word is not in the dictionary.
 *
 * The map data structure provides efficient lookup operations using a balanced binary search tree,
 * resulting in logarithmic time complexity for retrieval.
 *
 */
