/**
 * Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
 * a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
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

char get_offset_char(int val) {
  if (val < 10) {
    return val + '0';
  } else {
    return val - 10 + 'a';
  }
}

// Legal arguments for b are any values in the inclusive range [2, 36], where we
// first use the numeric digits 0-9 then the alphabetic characters a-z.
void itob(int n, char s[], int b) {
  int i, sign;
  i = 0;
  // We need to unroll the first loop iteration
  // for n = INT_MIN since -INT_MIN is UB.
  if (n == INT_MIN) {
    int val = -(n % b);
    s[i++] = get_offset_char(val);
    // At this point we are good since INT_MIN/10 < INT_MIN.
    n /= b;
  }
  if ((sign = n) < 0) { /* record sign */
    n = -n;             /* make n positive */
  }
  do { /* generate digits in reverse order */
    int val = n % b;
    s[i++] = get_offset_char(val); /* get next digit */
  } while ((n /= b) > 0);          /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main() {
  char s[MAX_STRING_SIZE];

  int test_value = 128489;
  int base = 8;
  itob(test_value, s, base);
  printf("%d as string in base %d = %s\n", test_value, base, s);

  base = 16;
  itob(test_value, s, base);
  printf("%d as string in base %d = %s\n", test_value, base, s);

  base = 1;
  itob(test_value, s, base);
  printf("%d as string in base %d = %s\n", test_value, base, s);

  base = 27;
  itob(test_value, s, base);
  printf("%d as string in base %d = %s\n", test_value, base, s);

  test_value= INT_MIN;
  base = 16;
  itob(test_value, s, base);
  printf("%d as string in base %d = %s\n", test_value, base, s);
  return 0;
}
