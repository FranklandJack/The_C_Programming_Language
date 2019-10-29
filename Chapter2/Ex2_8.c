/**
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 */

#include <limits.h>
#include <stdio.h>

int rightrot(int x, int n) {
  return ((unsigned int)x >> n) |
         (x << ((sizeof(x) * CHAR_BIT) - (n % (sizeof(x) * CHAR_BIT))));
}

int main() {
  printf("rightrot(0xdeadbeaf, 8) = 0x%x\n", rightrot(0xdeadbeaf, 8));
  return 0;
}
