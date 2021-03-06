/**
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 */

#include <stdio.h>

int invert(int x, int p, int n) {
  return (~(x & ((~(~0 << n)) << (p + 1 - n))) & (~(~0 << n) << (p + 1 - n))) |
         (x & ~((~(~0 << n)) << (p + 1 - n)));
}

int main() {
  printf("invert(0xdeadbeaf, 10 , 7) = 0x%x\n", invert(0xdeadbeaf, 10, 7));
  return 0;
}
