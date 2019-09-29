/**
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */
#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim) {
  int c, i;
  int whitespace = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == ' ' || c == '\t') {
      ++whitespace;
    } else {
      whitespace = 0;
    }
    s[i] = c;
  }

  if (c == '\n') {
    s[i - whitespace] = c;
    ++i;
  }
  s[i - whitespace] = '\0';
  return i;
}

int main() {
  char line[MAXLINE];
  int len = 0;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    printf("%s", line);
  }
  return 0;
}
