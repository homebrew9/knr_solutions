/* Write a program to print all input lines that are longer than 80
 * characters.
 * Usage: ./ex1_17 < sample_file_1.txt
 *        ./ex1_17 < sample_file_2.txt
 */
#include <stdio.h>
#define MAX 10

int main() {
  int c, i, j;
  char line[MAX];
  i = 0;
  while ((c = getchar()) != EOF) {
    if (c != '\n' && i < MAX) {
      line[i] = c;
      i++;
    } else if (c != '\n' && i == MAX) {
      for (j=0; j<i; j++) { printf ("%c", line[j]); }
      putchar(c);
      i++;
    } else if (c != '\n' && i > MAX) {
      putchar(c);
      i++;
    } else if (c == '\n') {
      if (i > MAX) { putchar(c); }
      i = 0;
    }
  }
  return 0;
}
