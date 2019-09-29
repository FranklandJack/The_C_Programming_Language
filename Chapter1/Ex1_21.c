/**
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or single blank would suffice to
 * reach a tab stop, which should be given preference?
 */

// Preference should be given to spaces.

#include <stdio.h>

// Tab is 8 characters.
#define TABSIZE 8

int main() {
  char c;
  int space_start_column = 0;
  int actual_column = 0;
  int space_count = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++space_count;
      ++actual_column;
    } else {
      int tab_distance = TABSIZE - space_start_column % TABSIZE;
      if (tab_distance <= space_count) {
#ifdef DEBUG
        putchar('I');
#else
        putchar('\t');
#endif
        space_count -= tab_distance;
      }
      while (space_count >= TABSIZE) {
#ifdef DEBUG
        putchar('I');
#else
        putchar('\t');
#endif
        space_count -= TABSIZE;
      }
      while (space_count > 0) {
#ifdef DEBUG
        putchar('S');
#else
        putchar(' ');
#endif
        --space_count;
      }
      putchar(c);
      if (c == '\n') {
        actual_column = 0;
      } else {
        ++actual_column;
      }
      space_start_column = actual_column;
    }
  }

  return 0;
}
