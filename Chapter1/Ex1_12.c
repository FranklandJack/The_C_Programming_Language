/**
 * Exercise 1-12. Write a program that prints its input one word per line.
 */
#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  char c;
  int state = OUT;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t') {
      putchar(c);
      state = IN;
    } else if (state == IN) {
      putchar('\n');
      state = OUT;
    }
  }
  return 0;
}
