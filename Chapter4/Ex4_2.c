/**
 * Extend atof to handle scientific notation of the form 123.45e-6
 * were a floating-point number may be followed by an e or R ad an
 * optionally signed exponent.
 */

#include <ctype.h>
#include <stdio.h>

double atof(char s[]) {
  int i;
  for (i = 0; isspace(s[i]); ++i) {
    ;
  }

  int sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    ++i;
  }

  double val;
  for (val = 0.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    ++i;
  }
  int power;
  for (power = 1.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  double result = sign * val / power;

  if (s[i] == 'e' || s[i] == 'E') {
    ++i;
    int exponent_sign = (s[i] == '-') ? -1 : +1;
    if (s[i] == '+' || s[i] == '-') {
      ++i;
    }
    int exponent = 0;
    while (isdigit(s[i])) {
      exponent = exponent * 10 + (s[i++] - '0');
    }
    int exponent_power = 1;
    while (exponent-- > 0) {
      exponent_power *= 10;
    }
    if (exponent != 1) {
      if (exponent_sign == 1) {
        result *= exponent_power;
      } else {
        result /= exponent_power;
      }
    }
  }
  return result;
}

int main() {
  printf("atof(1.1234) = %f\n", atof("1.234"));
  printf("atof(-12345.6789e-3) = %f\n", atof("-12345.6789e-3"));
  printf("atof(-12345.6789E+4) = %f\n", atof("-12345.6789E+4"));
  printf("atof(-12345.6789E3) = %f\n", atof("-12345.6789E3"));
  return 0;
}
