/**
 * Exercise 1-19. Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char s[], int len) {
  for (int i = 0; i < len / 2; ++i) {
    char a = s[i];
    char b = s[len - i - 1];
    s[i] = b;
    s[len - i - 1] = a;
  }
}

int main() {
  char line[MAXLINE];
  int len = 0;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }
  return 0;
}


