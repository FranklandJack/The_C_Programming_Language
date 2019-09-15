/**
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion.
 */
#include <stdio.h>

float fahr_to_cels(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

int main() {
  printf("Fahrenheit\tCelcius\n");
  for (int fahr = 0; fahr <= 300; fahr += 20)
    printf("%10d\t%7.1f\n", fahr, fahr_to_cels(fahr));
  return 0;
}
