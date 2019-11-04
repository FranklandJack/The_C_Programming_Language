/**
 * Exercise 4-1. Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char s[], int lim) {
  char c;
  int i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int strindex(char s[], char t[]) {
  int i, j, k;
  for (i = 0; s[i] != '\0'; ++i) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k) {
      ;
    }
    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}

void reverse(char source[], char destination[]) {
  int length = strlen(source);
  int i, j;
  int end = (source[length - 1] == '\n') ? length - 1 : length;
  for (i = 0, j = end - 1; i < end; ++i, --j) {
    destination[i] = source[j];
  }
}

int strrindex(char source[], char searchfor[]) {
  char reversed_source[MAXLINE];
  char reversed_searchfor[MAXLINE];

  reverse(source, reversed_source);
  reverse(searchfor, reversed_searchfor);
  return strindex(reversed_source, reversed_searchfor);
}

char pattern[] = "ould";

int main() {
  char line[MAXLINE];
  int found = 0;

  while (my_getline(line, MAXLINE) > 0) {
    int position = strrindex(line, pattern);
    if (position >= 0) {
      printf("%s found in %sat index %d from rhs\n", pattern, line, position);
      found++;
    }
  }
  return found;
}
