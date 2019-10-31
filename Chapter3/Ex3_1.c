/**
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only
 * one test inside the loop and measure the difference in run-time.
 */

#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1048576
#define SEARCH_VALUE 457

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}

int binsearch_improved(int x, int v[], int n) {
  if (n == 0) {
    return -1;
  }
  int low = 0;
  int high = n - 1;
  int mid;
  while (low != high) {
    mid = (low + high) / 2;
    if (v[mid] < x) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return (v[high] == x) ? high : -1;
}

int main() {
  // Fill the test array.
  int v[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; ++i) {
    v[i] = i + 31;
  }

  printf("Starting binsearch...\n");
  clock_t start_binsearch = clock();
  int binsearch_results = binsearch(SEARCH_VALUE, v, ARRAY_SIZE);
  clock_t end_binsearch = clock();
  printf("binsearch finished in %fs\n",
         (float)(end_binsearch - start_binsearch) / CLOCKS_PER_SEC);
  printf("binsearch found %d at index %d\n", SEARCH_VALUE, binsearch_results);

  printf("Starting binsearch_improved...\n");
  clock_t start_binsearch_immproved = clock();
  int binsearch_improved_results =
      binsearch_improved(SEARCH_VALUE, v, ARRAY_SIZE);
  clock_t end_binsearch_improved = clock();
  printf("binsearch_improved finished in %fs\n",
         (float)(end_binsearch_improved - start_binsearch_immproved) /
             CLOCKS_PER_SEC);
  printf("binsearch_improved found %d at index %d\n", SEARCH_VALUE,
         binsearch_improved_results);
  return 0;
}
