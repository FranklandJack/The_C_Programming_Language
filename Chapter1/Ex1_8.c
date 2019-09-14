/**
 * Exercise 1-8. Write a program to count blanks, tabs and newlines.
 */
#include <stdio.h>

main() {
  char c;
  long bc, tc, nc;

  bc = tc = nc = 0;
  while ((c = getchar()) != EOF) {
    switch (c) {
    default:
      continue;
    case ' ':
      ++bc;
      break;
    case '\t':
      ++tc;
      break;
    case '\n':
      ++nc;
      break;
    }
  }

  printf("Character\tCount\n");
  printf("Blanks   \t%5ld\n", bc);
  printf("Tabs     \t%5ld\n", tc);
  printf("Newlines \t%5ld\n", nc);
}
