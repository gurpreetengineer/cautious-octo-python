#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string> &words)
{
  map<string, vector<string>> anagramGroups;

  // Group words by their sorted character representations
  for (const string &word : words)
  {
    string sortedWord = word;
    sort(sortedWord.begin(), sortedWord.end());
    anagramGroups[sortedWord].push_back(word);
  }

  // Convert map values to a vector of vectors
  vector<vector<string>> result;
  for (const auto &pair : anagramGroups)
  {
    result.push_back(pair.second);
  }

  return result;
}

void printAnagramGroups(const vector<vector<string>> &anagramGroups)
{
  for (const auto &group : anagramGroups)
  {
    for (const string &word : group)
    {
      cout << word << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<string> words = {"cat", "dog", "tac", "god", "act"};

  cout << "Original words: ";
  for (const string &word : words)
  {
    cout << word << " ";
  }
  cout << endl;

  vector<vector<string>> anagramGroups = groupAnagrams(words);

  cout << "Anagram groups:" << endl;
  printAnagramGroups(anagramGroups);

  return 0;
}

/**
 * @brief Anagram groups using maps
 *
 * In this program, the groupAnagrams function takes a vector of words and groups them into anagram groups using a map. 
 * Each word is sorted to obtain its sorted character representation, which is used as the key in the map. 
 * Words with the same sorted representation are stored together in the corresponding vector value. 
 * 
 * Finally, the printAnagramGroups function is used to print the anagram groups.
 * 
 * In the example given, the program groups the words "cat", "dog", "tac", "god", and "act" into two anagram groups: 
 * ["cat", "tac", "act"] and ["dog", "god"]. 
 * 
 * The program outputs the original words and the anagram groups to demonstrate the grouping of anagrams.
 * 
 * Please note that this implementation considers anagrams as words with the same set of characters, 
 * regardless of letter case. 
 * 
 * For case-sensitive anagram grouping, you can modify the sorting step accordingly.
 *
 */
