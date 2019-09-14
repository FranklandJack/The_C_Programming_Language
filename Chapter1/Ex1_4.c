/**
 * Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit
 * table.
 */
#include <stdio.h>
/**
 * Print Celsius-Fahrenheit table for Celsius = -17.8, -6.7, ..., 137.8;
 * floating-point version.
 */
main() {
  float celsius, fahr;
  float lower, upper, step;

  lower = -17.8; /* lower limit of temperature table */
  upper = 148.9; /* upper limit */
  step = 11.1;   /* step size */

  printf("Celsius\tFahrenheit\n");
  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%7.1f\t%10.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
