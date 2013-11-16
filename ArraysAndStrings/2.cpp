/*
 * Implement a function `void reverse(char *str)` in C or C++ which
 * reverse a null-terminated string.
 */

#include <iostream>

using namespace std;

void reverse(char *str) {
  char *head = str, *tail = str;
  while(*tail != '\0') {
    tail++;
  }
  tail--;

  char tmp = '\0';
  while(head < tail) {
    tmp = *head;
    *head++ = *tail;
    *tail-- = tmp;
  }
}

int main() {
  char abc[] = "abcdefg";
  reverse(abc);

  cout << abc << endl;
  return 0;
}
