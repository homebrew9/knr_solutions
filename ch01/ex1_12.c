/* Write a program that prints its input one word per line.
 * Usage: ./ex1_12 < sample_file.txt
 */
#include <stdio.h>
main () {
  int c;
  c = getchar();
  while (c != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {putchar('\n');}
    else {putchar(c);}
    c = getchar();
  }
}

