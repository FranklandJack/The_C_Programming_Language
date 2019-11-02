/**
 * Exercise 3-1. Write a function escape(s, t) that converts characters like
 * newline and tab into visable escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a functino for the other direction as
 * well, converting escape sequences into the real characters.
 */

#include <stdio.h>

void escape(char s[], char const t[]) {
  int i = 0;
  int j = 0;
  char c;
  while (1) {
    switch (c = t[i]) {
    case '\t':
      s[j++] = '\\';
      s[j] = 't';
      break;
    case '\n':
      s[j++] = '\\';
      s[j] = 'n';
      break;
    case '\a':
      s[j++] = '\\';
      s[j] = 'a';
      break;
    case '\b':
      s[j++] = '\\';
      s[j] = 'b';
      break;
    case '\v':
      s[j++] = '\\';
      s[j] = 'v';
      break;
    case '\f':
      s[j++] = '\\';
      s[j] = 'f';
      break;
    case '\r':
      s[j++] = '\\';
      s[j] = 'r';
      break;
    case '\\':
      s[j++] = '\\';
      s[j] = '\\';
      break;
    case '\"':
      s[j++] = '\\';
      s[j] = '"';
      break;
    case '\0':
      s[j] = '\0';
      return;
    default:
      s[j] = c;
      break;
    }
    ++j;
    ++i;
  }
}

void convert(char s[], char const t[]) {
  int i = 0;
  int j = 0;
  int c;
  while (1) {
    switch (c = t[i]) {
    case '\\': {
      char cn = t[i + 1];
      switch (cn) {
      case 't':
        s[j] = '\t';
        ++i;
        break;
      case 'n':
        s[j] = '\n';
        ++i;
        break;
      case 'a':
        s[j] = '\a';
        ++i;
        break;
      case 'b':
        s[j] = '\b';
        ++i;
        break;
      case 'v':
        s[j] = '\v';
        ++i;
        break;
      case 'f':
        s[j] = '\f';
        ++i;
        break;
      case 'r':
        s[j] = '\r';
        ++i;
        break;
      case '"':
        s[j] = '\"';
        ++i;
        break;
      default:
        s[j] = '\\';
      }
      break;
    }
    case '\0':
      s[j] = '\0';
      return;
    default:
      s[j] = t[i];
      break;
    }
    ++i;
    ++j;
  }
}

int main() {
  char t[] = "He\tllo\n Wo\trl\nd";
  char s[sizeof(t) / sizeof(t[0]) + 4];
  char u[sizeof(t) / sizeof(t[0])];
  escape(s, t);
  printf("After escaping:\n s = %s\n t = %s\n", s, t);
  convert(u, s);
  printf("After converting:\n u = %s\n s = %s\n", u, s);
  return 0;
}
