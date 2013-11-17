/*
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string *aabcccccaaa* would become
 * *a2b1c5a3*. If the "compressed" string would not become smaller than the
 * original string, your method should return the oringal string.
 */

#include <iostream>
#include <sstream>

using namespace std;

string *compress(string *str) {
  stringstream compressedStream;
  char last = '\0';
  int count = 0;
  for (string::iterator i = str->begin(); i != str->end(); i++)
  {
    if (last != *i && count > 0)
    {
      compressedStream << last << count;
      count = 0;
    }
    last = *i;
    count++;
  }
  compressedStream << last << count;
  string *compressed = new string(compressedStream.str());

  if (compressed->length() < str->length())
  {
    return compressed;
  }
  return str;
}

int main() {
  string *origin = new string("aabcccccaaa");
  string *compressed = compress(origin);

  cout << *origin << " -> " << *compressed << endl;
  return 0;
}
