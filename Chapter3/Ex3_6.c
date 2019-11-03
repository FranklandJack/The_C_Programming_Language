/**
 * Exercise 3-6. Write a version of itoa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
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
void itoa(int n, char s[], int field_width) {
  int i, sign;
  i = 0;
  // We need to unroll the first loop iteration
  // for n = INT_MIN since -INT_MIN is UB.
  if (n == INT_MIN) {
    s[i++] = -(n % 10) + '0';
    // At this point we are good since INT_MIN/10 < INT_MIN.
    n /= 10;
  }
  if ((sign = n) < 0) { /* record sign */
    n = -n;             /* make n positive */
  }
  do {                     /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0); /* delete it */

  int current_length = strlen(s) - (sign < 0);
  int required_padding = field_width - current_length;
  for (int j = 0; j < required_padding; ++j) {
    s[i++] = '0';
  }

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main() {
  int test_value = 23452;
  char s[MAX_STRING_SIZE];
  int field_width = 32;
  itoa(test_value, s, field_width);
  printf("%d as string padded to %d characters = %s\n", test_value, field_width,
         s);
  return 0;
}

