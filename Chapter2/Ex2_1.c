/**
 * Exercise 2-1. Write a program to determine the ranges of char, short, int and
 * long variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

// The C standard doesn't prescribe a specific representation for integers or floats.
// so there is no portable way to calculate the ranges of these types.

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("From standard headers:\n");

    printf("char bits = %u\n", CHAR_BIT);
    printf("max bytes in multibyte character = %u\n", MB_LEN_MAX);
    printf("char: [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: [%u, %u]\n", 0, UCHAR_MAX);
    printf("signed char: [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);

    printf("short: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: [%u, %u]\n", 0, USHRT_MAX);

    printf("int: [%d, %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int: [%u, %u]\n", 0, UINT_MAX);

    printf("long: [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned int: [%lu, %lu]\n", 0L, ULONG_MAX);

    printf("float: [%.10e, %.10e]\n", FLT_MIN, FLT_MAX);
    printf("double: [%.10e, %.10e]\n", DBL_MIN, DBL_MAX);
    printf("long double: [%.10Le, %.10Le]\n", LDBL_MIN, LDBL_MIN);

    return 0;
}
