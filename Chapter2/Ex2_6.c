/**
 * Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged
 */

#include <stdio.h>

int setbits(int x, int p, int n, int y) {
  return (~((~(~0u << n)) << (p + 1 - n)) & x) |
         (((~(~0u << n)) & y) << (p + 1 - n));
}

int main() {
  printf("setbits(0xdeadbeaf, 5, 3, 0xbadc0de) = 0x%x\n",
         setbits(0xdeadbeaf, 5, 3, 0xbadc0de));
  return 0;
}
