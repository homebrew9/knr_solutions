/* Verify that the expression getchar() != EOF is 0 or 1.
 * Usage: ./ex1_06 < small_file.txt
 *        ./ex1_06 < zero_byte.txt
 *        ./ex1_06 < ex1_01.c
 */
#include <stdio.h>
main() {
  int c;
  c = getchar();              // reads the first character
  printf ("%d\n", c != EOF);  // prints 1 for a non-zero byte file; 0 otherwise
  while (c != EOF) {
    // putchar(c);
    c = getchar();
  }
  printf ("%d\n", c != EOF);  // prints 0 for any size file
}

