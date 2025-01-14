/* Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way.
 * Usage: ./ex1_09 < many_blanks.txt
 * Note: I don't know any way of capturing backspaces, so I cannot handle it.
 */
#include <stdio.h>
main () {
  int c;
  c = getchar();
  while (c != EOF) {
    if (c == '\t') {printf ("%c%c", '\\', 't');}
    else if (c == '\\') {printf ("%c%c", '\\', '\\');}
    else {putchar(c);}
    c = getchar();
  }
}

