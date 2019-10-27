/**
 * Exercise 2-5. Write the function any(s1, s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2.
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

int any(char s1[], char s2[]) {
  for (int i = 0; s1[i] != '\0'; ++i) {
    if (contains(s2, s1[i])) {
      return i;
    }
  }
  return -1;
}

int main() {
  char s1[] = "foobarbaz";
  char s2[] = "xy";
  char s3[] = "cam";
  printf("any(\"foobarbaz\", \"cam\") = %d\n", any(s1, s2));
  printf("any(\"foobarbaz\", \"fbb\") = %d\n", any(s1, s3));
  return 0;
}
