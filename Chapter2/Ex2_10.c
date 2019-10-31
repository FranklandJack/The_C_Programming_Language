/**
 * Exercise 2-10. Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

char lower(char c) { return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; }

int main() {
  char uppers[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char lowers[] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0, s = (sizeof(uppers) - 1) / sizeof(uppers[0]); i < s; ++i) {
    char c = uppers[i];
    printf("lower(%c) = %c\n", c, lower(c));
  }
  for (int i = 0, s = (sizeof(lowers) - 1) / sizeof(lowers[0]); i < s; ++i) {
    char c = lowers[i];
    printf("lower(%c) = %c\n", c, lower(c));
  }
  return 0;
}
