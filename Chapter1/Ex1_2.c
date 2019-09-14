/**
 * Exercise 1-2. Experiment to find out what happens when printf's argument
 * string contains \c, where c is some character not listed above.
 */
#include <stdio.h>

main() {
  // Tab.
  printf("hello,\tworld");
  printf("\n");

  // Backspace.
  printf("hello,\b world");
  printf("\n");

  // Quote.
  printf("hello, world\"");
  printf("\n");

  // Backslash.
  printf("hello, world\\");
  printf("\n");
}
