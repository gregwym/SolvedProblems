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
  string *compressed = new string();
  char last = '\0';
  int count = 0;
  for (int i = 0; i < str->length(); ++i)
  {
    if (last != str->at(i) && count > 0)
    {
      compressed->push_back(last);
      stringstream countStr;
      countStr << count;
      compressed->append(countStr.str());
      count = 0;
    }
    last = str->at(i);
    count++;
  }

  compressed->push_back(last);
  stringstream countStr;
  countStr << count;
  compressed->append(countStr.str());

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
