/* Write a program to count blanks, tabs and newlines.
 * Usage: ./ex1_08 < sample_file.txt
 */
#include <stdio.h>
main () {
  int c;
  int bl, tb, nl;
  bl = tb = nl = 0;
  c = getchar();
  while (c != EOF) {
    if (c == ' ') {bl++;}
    else if (c == '\t') {tb++;}
    else if (c == '\n') {nl++;}
    c = getchar();
  }
  printf ("No. of blanks   = %d\n", bl);
  printf ("No. of tabs     = %d\n", tb);
  printf ("No. of newlines = %d\n", nl);
}
