/**
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */
#include <limits.h>
#include <stdio.h>

int main() {
  int freqs[UCHAR_MAX];
  for (int i = 0; i < UCHAR_MAX; ++i)
    freqs[i] = 0;

  char c;
  while ((c = getchar()) != EOF) {
    freqs[c]++;
  }

  printf("Character\tFrequency\n");

  for (int i = 0; i < UCHAR_MAX; ++i) {
    int freq = freqs[i];
    if (freq != 0) {
      switch (i) {
      default:
        printf("%c            \t", i);
        break;
      case '\t':
        printf("\\t        \t");
        break;
      case '\n':
        printf("\\n        \t");
        break;
      case '\\':
        printf("\\        \t");
        break;
      case '\b':
        printf("\b        \t");
        break;
      }

      for (int j = 0; j < freq; ++j) {
        putchar('*');
      }
      putchar('\n');
    }
  }
  return 0;
}
