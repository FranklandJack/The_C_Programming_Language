/**
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variables or a symbolic
 * constant?
 */

// n should be a symbolic constant since it is assumed to take a single value
// which is known at compile time.

#include <stdio.h>

// Tab is 8 characters.
#define TABSIZE 8

int main() {

  char c;
  int column;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int remainder = column % TABSIZE;
      int fill = TABSIZE - remainder;
      for (int i = 0; i < fill; ++i) {
        putchar(' ');
      }
    } else {
      putchar(c);
      ++column;
    }
    if (c == '\n') {
      column = 0;
    }
  }
  return 0;
}
