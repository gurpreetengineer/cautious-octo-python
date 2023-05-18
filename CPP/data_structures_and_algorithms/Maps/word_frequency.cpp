#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

map<string, int> getWordFrequency(const string &text)
{
  map<string, int> frequencyMap;

  // Split the text into words
  stringstream ss(text);
  string word;
  while (ss >> word)
  {
    // Remove punctuation marks and convert to lowercase
    string cleanedWord;
    for (char c : word)
    {
      if (isalpha(c))
      {
        cleanedWord += tolower(c);
      }
    }

    // Update the frequency map
    if (!cleanedWord.empty())
    {
      frequencyMap[cleanedWord]++;
    }
  }

  return frequencyMap;
}

void printWordFrequency(const map<string, int> &frequencyMap)
{
  for (const auto &pair : frequencyMap)
  {
    cout << pair.first << ": " << pair.second << endl;
  }
}

int main()
{
  string text = "This is a sample text. It contains words that may repeat. This text is used for word frequency analysis.";

  map<string, int> frequencyMap = getWordFrequency(text);

  cout << "Word Frequency:" << endl;
  printWordFrequency(frequencyMap);

  return 0;
}

/**
 * @brief Word frequency counter using maps explanation
 *
 * In this program, the getWordFrequency function takes a string text as input and
 * @returns a map that contains the frequency of each word in the text.
 * It uses a stringstream to split the text into individual words and
 * then cleans each word by removing punctuation marks and converting it to lowercase.
 * The cleaned word is then used as a key in the frequency map, and its corresponding value is incremented.
 *
 * The printWordFrequency function is used to print the word frequency map.
 * It iterates over each pair in the map and displays the word along with its frequency.
 *
 * In the example given, the program analyzes a sample text and prints the frequency of each word.
 * You can modify the text variable to analyze different text documents.
 *
 * Note that this program assumes that words are separated by whitespace and considers punctuation marks as part of the word.
 * If you have specific requirements for word splitting or handling punctuation,
 * you can customize the logic in the getWordFrequency function.
 *
 */
