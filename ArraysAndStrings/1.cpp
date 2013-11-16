/*
 * Implement an algorithm to determin if a string has all unique characters.
 * What if you cannot use additional data structures?
 */

#include <iostream>

using namespace std;

#define NUM_OF_CHAR 256

int main() {
  string str;
  getline(cin, str);

  bool charMap[NUM_OF_CHAR] = { false };
  const char *chars = str.c_str();
  for (int i = 0; i < str.length(); ++i)
  {
    char c = chars[i];
    if (charMap[c])
    {
      cout << "Found duplicate" << endl;
      return 0;
    }
    charMap[c] = true;
  }

  cout << "No duplicate" << endl;
  return 0;
}
