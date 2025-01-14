/* Write a program to copy its input to its output, replacing each string of one
 * or more blanks by a single blank.
 * Usage: ./ex1_09 < many_blanks.txt
 */
#include <stdio.h>
main () {
  int c;
  int toggle = 0;
  c = getchar();
  while (c != EOF) {
    if (c == ' ' && ! toggle) {
      putchar(c);
      toggle = 1;
    } else if (c != ' ') {
      putchar(c);
      if (toggle) {toggle = 0;}
    }
    c = getchar();
  }
}

