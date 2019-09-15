/**
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */
#include <stdio.h>
// Assume we don't exceed 1024 words of different lengths,
// otherwise we would need to dynamically allocate memory.
#define MAX_WORD_COUNT 24
#define IN 1
#define OUT 0

// Horizontal printing implementation.
int main() {

  // Array to hold the frequencies.
  int wl_counts[MAX_WORD_COUNT];
  for (int i = 0; i < MAX_WORD_COUNT; ++i) {
    wl_counts[i] = 0;
  }

  // Count the words.
  char c;
  int state = OUT;
  int wl = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      state = IN;
      ++wl;
    } else if (IN == state) {
      state = OUT;
      wl_counts[wl - 1]++;
      wl = 0;
    }
  }

  // Find the highest frequency.
  int max_idx = 0;
  for (int i = 0; i < MAX_WORD_COUNT; ++i) {
    int freq = wl_counts[i];
    max_idx = max_idx < freq ? i : max_idx;
  }

  putchar('\n');

#ifndef VERTICAL
  // Print a header.
  printf("Word Length\tFrequency\n");

  // Print the frequencies with *s.
  for (int i = 0; i < MAX_WORD_COUNT; ++i) {
    if (wl_counts[i] != 0) {
      printf("%2d      \t", i + 1);
      for (int j = 0, f = wl_counts[i]; j < f; ++j) {
        putchar('*');
      }
      putchar('\n');
    }
  }

// Vertical printing implementation.
#else
  for (int i = wl_counts[max_idx]; i > 0; --i) {
    for (int j = 0; j < MAX_WORD_COUNT; ++j) {
      if (wl_counts[j] != 0 && wl_counts[j] >= i) {
        printf("* ");
      }
    }
    putchar('\n');
  }
  for (int i = 0; i < MAX_WORD_COUNT; ++i) {
    if (wl_counts[i] != 0) {
      printf("%d ", i + 1);
    }
  }
  putchar('\n');
#endif
  return 0;
}
