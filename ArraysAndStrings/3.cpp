/*
 * Given two strings, write a method to decide if one is a permutation
 * of the other.
 */

#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_CHAR 256

bool isPermutation(const char* a, const char* b, int aLen, int bLen) {
  if (aLen != bLen)
  {
    return false;
  }
  int aCharCount[NUM_OF_CHAR] = { 0 };
  int bCharCount[NUM_OF_CHAR] = { 0 };

  for (int i = 0; i < aLen; ++i)
  {
    aCharCount[a[i]]++;
    bCharCount[b[i]]++;
  }

  for (int i = 0; i < NUM_OF_CHAR; ++i)
  {
    if (aCharCount[i] != bCharCount[i])
    {
      return false;
    }
  }
  return true;
}

int main() {
  string a = "1233345";
  string b = "3145323";

  cout << isPermutation(a.c_str(), b.c_str(), a.length(), b.length()) << endl;
  return 0;
}
