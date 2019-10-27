/**
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits  (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through G.
 */

#include <stdio.h>
int htoi(char s[]) {
  int i = 0;
  // Skip to the first hex character if there is an 0x or 0X at the
  // beggning of the string.
  if (s[0] == '0' && (s[1] == 'x' || s[2] == 'X')) {
    i = 2;
  }
  int sum = 0;
  while (s[i] != '\0') {
    char c = s[i];
    // Check if the character is upper case, if so convert it to lower case.
    if (c >= 'A' && c <= 'F') {
      c += 'a' - 'A';
    }

    int val = 0;
    if (c >= 'a' && c <= 'z') {
      val += c - 'a' + 10;
    } else if (c >= 0 && c <= 9) {
      val += c - '0';
    }
    sum = (16 * sum) + val;
    ++i;
  }
  return sum;
}

int main() {
  printf("%u\n", htoi("0xdeadBEaF"));
  return 0;
}
