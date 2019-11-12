/** Exercie 4-5. Add access to library functions like sin, exp and pow. See
 * <math.h> in Appendix B, Section 4.
 */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
void clear(void);
void print_top_element(void);
void duplicate(void);
void swap(void);

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      push((int)pop() % (int)op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    case 'c':
      clear();
      break;
    case 'p':
      print_top_element();
      break;
    case 'd':
      duplicate();
      break;
    case 's':
      swap();
      break;
    case 'i':
      push(sin(pop()));
      break;
    case 'e':
      push(exp(pop()));
      break;
    case 'o':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// clear: clear the stack.
void clear(void) { sp = 0; }

// print: print element at top of stack.
void print_top_element(void) {
  double tmp = pop();
  printf("\t%.8g\n", tmp);
  push(tmp);
}

// duplicate: duplicate the top element of the stack.
void duplicate(void) {
  double tmp = pop();
  push(tmp);
  push(tmp);
}

// swap: swap the two elements at the top of the stack.
void swap() {
  double tmp1 = pop();
  double tmp2 = pop();
  push(tmp1);
  push(tmp2);
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-') {
    return c; /* not a number */
  }
  i = 0;
  if (c == '-') {
    char next_digit = getch();
    if (!isdigit(next_digit)) {
      ungetch(next_digit);
      return c;
    } else {
      s[i] = c;
      ungetch(next_digit);
    }
  }
  if (isdigit(c) || c == '-') { /* collect integer part */
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }

  if (c == '.') { /* collect fractional part */
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }
  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

/* push character back on input */
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
