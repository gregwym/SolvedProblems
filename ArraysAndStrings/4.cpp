/*
 * Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the end of the string
 * to hold the additional characters, and that you are given the "true" length
 * of the string. (Note: if implementing in Java, please use a character array
 * so that you can perform this operation in place.)
 */

#include <queue>
#include <iostream>

using namespace std;

void urify(char *str, int len) {
  queue<char> onHold;
  char *insert = str, *read = str;
  while(read - str < len || !onHold.empty()) {
    if (read - str < len)
    {
      char c = *read++;
      if (c == ' ')
      {
        onHold.push('%');
        onHold.push('2');
        onHold.push('0');
      } else {
        onHold.push(c);
      }
    }
    *insert++ = onHold.front();
    onHold.pop();
  }
}

int main() {
  char str[100] = "test test test";
  int len = sizeof(str) / sizeof(*str);
  urify(str, len);
  cout << str << endl;
  return 0;
}
