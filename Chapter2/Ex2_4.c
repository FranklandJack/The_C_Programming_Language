/**
 * Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes each
 * character in s2 that matches any character in the string s2.
 */

#include <stdio.h>

int contains(char s[], char c) {
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c) {
      return 1;
    }
  }
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  for (i = j = 0; s1[i] != '\0'; ++i) {
    if (!contains(s2, s1[i])) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

int main() {
  char s1[] = "foobarbaz";
  char s2[] = "bar";
  squeeze(s1, s2);
  printf("%s\n", s1);
  return 0;
}
