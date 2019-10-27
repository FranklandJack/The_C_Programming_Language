/**
 * Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAX_COLUMN 10
#define BREAK_COUMN (MAX_COLUMN + 3)
#define TAB_SIZE 8

int main() {
  int c;
  int column = 0;
  while ((c = getchar()) != EOF) {
    if (column < MAX_COLUMN) {
      putchar(c);
      if (c != '\n') {
        column += (c == '\t') ? TAB_SIZE : 1;
      } else {
        column = 0;
      }
    } else if (column >= BREAK_COUMN) {
      putchar('-');
      putchar('\n');
      if (c == ' ') {
        column = 0;
      } else {
        putchar(c);
        column = 1;
      }
    } else if (c == ' ' || c == '\n') {
      putchar('\n');
      column = 0;
    } else {
      putchar(c);
      ++column;
    }
  }
  return 0;
}
