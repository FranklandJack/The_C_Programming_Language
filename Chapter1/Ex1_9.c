/**
 * Exercise 1-9. Write a program to copy its input to its output, replacing
 * each string of one or more blanks by a single blank.
 */
#include <stdio.h>

int main() {
  for (char c = getchar(); c != EOF;) {
    putchar(c);
    if (' ' == c) {
      char d;
      while ((d = getchar()) == ' ')
        ;
      c = d;
    } else {
      c = getchar();
    }
  }

  return 0;
}
