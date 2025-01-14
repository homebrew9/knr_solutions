/* Just a test program to try out a few things mentioned in chapter 2 of K&R
 */

#include <stdio.h>

int main() {
  // declaration of a constant string; looks like the initialization must be
  // during the declaration itself.
  char arr[] = "Welcome to the world of C!";
  printf ("%s\n", arr);
  // the following do not work!
  //arr = "And here's yet another string";
  //arr[] = "And here's yet another string";
  
  enum months {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
  printf ("%d\n", SEP);  // prints 9
  return 0;
}
