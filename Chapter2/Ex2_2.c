/**
 * Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 */

#include <stdio.h>
#define MAX_LINE 1000

void original_getline(char s[], int lim) {
  int i;
  char c;
  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
}

void new_getline(char s[], int lim) {
  int i;
  int c;
  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) != '\n') {
      if (c != EOF) {
        s[i] = c;
      }
    } else {
      break;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
}

int main() {
  char s[MAX_LINE];
  original_getline(s, MAX_LINE);
  printf("%s\n", s);
  new_getline(s, MAX_LINE);
  printf("%s\n", s);
  return 0;
}
