/**
 * Exercise 3-4. In a two's complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value of n
 * equal to -(2^(wordsize-1)). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 */

/**
 * Answer: In a two's complement number system, only integers in the half open
 * interval [-2^(n-1), 2^(n-1)) where n is the word size can be represented
 * (representing 2^(n-1) would require more bits. Therefore although
 * -(2^(wordsize -1)) can be represented 2^(wordsize-1) cannot. The algorithm
 * negates its input value for negative inputs, hence if the input is
 * -2^(wordsize-1) the result will be undefined behaviour since it overflows.
 */

#include <limits.h>
#include <printf.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 1024

void reverse(char s[]) {
  int length = strlen(s);
  int i, j;
  for (i = 0, j = length - 1; i < length / 2; ++i, --j) {
    char tmp = s[j];
    s[j] = s[i];
    s[i] = tmp;
  }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
  int i, sign;
  i = 0;
  // We need to unroll the first loop iteration
  // for n = INT_MIN since -INT_MIN is UB.
  if (n == INT_MIN) {
    s[i++] = -(n % 10) + '0';
    // At this point we are good since INT_MIN/10 < INT_MIN.
    n /= 10;
  }
  if ((sign = n) < 0) {        /* record sign */
    n = -n;                    /* make n positive */
  }
  do {                     /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0); /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}


int main() {
  char s[MAX_STRING_SIZE];

  int a = 23489;
  itoa(a, s);
  printf("%d as string = %s\n", a, s);

  int b = -823478;
  itoa(b, s);
  printf("%d as string = %s\n", b, s);

  int c = INT_MIN;
  itoa(c, s);
  printf("%d as string = %s\n", c, s);
  return 0;
}
