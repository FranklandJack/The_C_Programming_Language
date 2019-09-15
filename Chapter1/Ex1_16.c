/**
 * Exercise 1-16. Revise the main routine of the longest-line program to it will
 * correctly print the length of arbitrarily long input lines, and as much as
 * possible of the text.
 * note: int getline(char[], int) collides with ssize_t getline(char **, size_t
 * *, FILE *) in stdio.h since there is no namespacing or function overloading
 * in C. I assume that getline didn't exist in stdio.h when K&R was written. For
 * the purpose of this exercise has been renamed to mygetline.
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main() {
  int len;               /* current line length */
  int max;               /* maximum length seen so fat */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /* there was a line */
    printf("line: %slength: %d\n", longest, max);
  return 0;
}

/* mygetline: read line into s, return length */
int mygetline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  while (c != '\n' && c != EOF) {
    c = getchar();
    ++i;
  }
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
