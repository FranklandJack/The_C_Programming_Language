/**
 * Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 */

/**
 * Answer: Two cases - 1. x is odd.
 *                     2. x is even.
 * 1. x is odd -> last bit of x is set. x-1 turns this bit off leaving all
 * other bits untouched, so x & (x-1) is just x anded with itself except the
 * last bit is zero, hence x &= (x-1) just switches this last bit off.
 *
 * 2. x is even -> right most bit of x is not set, maybe more bits are not set.
 * In twos complement -1 = 0b11111... i.e. all bits set. x-1 = x + (-1), hence
 * x-1 will turn all zero bits to the right of the right most non-zero bit on,
 * and it will turn the rightmost bit off. The addition of the right most bit
 * will result in a carry bit that will travel to the next rightmost bit that is
 * not set and will turn it on. This works because any set bits to the immediate
 * left of the rightmost bit will also produce a carry bit since they are on in
 * the addition and so the propagation of the carry bit is the result of this
 * addition. Finally, for all bits to the right of the original rightmost bit x
 * & (x-1) = x since the bits are on in (x-1) and off in x, for the rightmost it
 * has been flipped, i.e. it is on in x and off in (x-1) so x & (x-1) = 0, for
 * all bits to the left of the rightmost bit, they are the same in x and (x-1),
 * hence x & (x -1) = x. Therefore x &= (x-1) has the effect of flipping the right
 * most bit.
 */

#include <stdio.h>

int bitcount(int x) {
    unsigned int count = 0;
    while(x) {
        x &= (x - 1);
        ++count;
    }
    return count;
}

int main() {
  printf("bitcount(11011110101011011011111010101111) = %d\n",
         bitcount(0xdeadbeaf));
  return 0;
}
