/**
 * Exercise 1-11. How would you test the work count program? What kinds of input
 * are most likely to uncover bugs if there are any?
 */
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/*count lines, words and characters in input */
main() {
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}

/**
 * Test for all cases of ' ', \n and \t individually and in combination.
 * Test for large input i.e. > 100,000 character files.
 * Test for files consisting only of tabs, newlines and blanks.
 *
 * Large input may uncover bugs, could overflow nc on platform where
 * int is only 16 bits hence -32767 <= nc <= 32768.
 */
