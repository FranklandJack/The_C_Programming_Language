/**
 * Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digit, and be prepared
 * to handle cases like a-b-c and a-z0-9 and -a-z Arrange that a leading or
 * trailing - is taken literally.
 */

#include <stdio.h>

#define MAX_STRING_SIZE 1024

#define TEST_CASE(TEST_STRING)                                                 \
  {                                                                            \
    char test_string[] = (TEST_STRING);                                        \
    char expanded_test_string[MAX_STRING_SIZE];                                \
    expand(test_string, expanded_test_string);                                 \
    printf("%s expanded to: %s\n", test_string, expanded_test_string);         \
  }                                                                            \
  (void)0

enum SHType { END_OF_STRING, SINGLE_CHAR, NUMERIC_RANGE, ALPHABETIC_RANGE };

static char *current_string;
static int current_index;
static int current_target_index;

int is_alpha(char c) { return (c >= 'a' && c <= 'z'); }

int is_capital_alpha(char c) { return (c >= 'A' && c <= 'Z'); }

int is_numeric(char c) { return (c >= '0' && c <= '9'); }

int is_alpha_numeric(char c) {
  return is_alpha(c) || is_capital_alpha(c) || is_numeric(c);
}

enum Character_Types { OTHER, LOWER, UPPER, NUMBER };

enum Character_Types get_character_type(char c) {
  if (is_alpha(c)) {
    return LOWER;
  } else if (is_capital_alpha(c)) {
    return UPPER;
  } else if (is_numeric(c)) {
    return NUMBER;
  } else {
    return OTHER;
  }
}

int lex(char *first_char, char *last_char) {
  *first_char = current_string[current_index];
  // If the first character isn't a number or letter, then it
  // cant be a short hand expression so just return.
  if (!is_alpha_numeric(current_string[current_index])) {
    ++current_index;
    *last_char = *first_char;
    // Need to handle the case we've hit the end of a string.
    return (*first_char == '\0') ? END_OF_STRING : SINGLE_CHAR;
  }

  // Even if the first charater is a number or letter if its
  // not followed by a '-' it isnt short hand, so just return.
  if (current_string[current_index + 1] != '-') {
    ++current_index;
    *last_char = *first_char;
    return SINGLE_CHAR;
  }

  // Now we are in the case were the string matches [A-Za-z0-9]-\.
  // but if the character following - isn't an alphanumeric character
  // of the same 'type' as the first one, it isn't a shorthand.
  int first_character_type = get_character_type(*first_char);
  if (first_character_type !=
      get_character_type(current_string[current_index + 2])) {
    ++current_index;
    *last_char = *first_char;
    return SINGLE_CHAR;
  }

  // Otherwise we have got a shorthand, we may not have reached the end of
  // the string, but we can return a lexme or whatever they are called.
  *last_char = current_string[current_index + 2];
  current_index += 3;
  return (first_character_type == NUMBER) ? NUMERIC_RANGE : ALPHABETIC_RANGE;
}

void expand_shorthand(enum SHType shtype, char start_char, char end_char,
                      char s[]) {
  // If its just a single char, then copy that into the new string.
  if (shtype == SINGLE_CHAR || shtype == END_OF_STRING) {
    s[current_target_index++] = start_char;
    return;
  }
  // Otherwise we need to expand and copy the range.
  char range = end_char - start_char;

  // range could potentially be negative if first character exceeds last.
  char c = start_char;
  for (int i = 0; i <= range; ++i, ++current_target_index, ++c) {
    s[current_target_index] = c;
  }
}

void expand(char s1[], char s2[]) {
  // Call into lex by first setting up the static arguments and then proccessing
  // until we reach the end of the string.
  current_string = s1;
  current_index = 0;
  char start_char, last_char;
  while (1) {
    enum SHType shorthand_type = lex(&start_char, &last_char);
    expand_shorthand(shorthand_type, start_char, last_char, s2);
    if (shorthand_type == END_OF_STRING) {
      break;
    }
  }
  current_target_index = 0;
}

int main() {
  TEST_CASE("a-z");
  TEST_CASE("A-Z");
  TEST_CASE("0-9");
  TEST_CASE("a-zA-Z0-9");
  TEST_CASE("a-b-c");
  TEST_CASE("-a-z");
  TEST_CASE("a-z-");
  return 0;
}
