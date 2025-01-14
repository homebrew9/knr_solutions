/* Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter?
 *
 * Usage: ./ex1_20.c < tabs_to_spaces.txt
 *
 */
#include <stdio.h>
#define MAX 500
#define TABLEN 4

int read_line (char arr[], int lim);
void reverse (char orig[], char reversed[], int size);

int main() {
  char line[MAX];
  char reversed_line[MAX];
  int len;

  while ((len = read_line (line, MAX)) > 0) {
    printf ("%s\n", line);
  }
}

int read_line (char arr[], int lim) {
  int c, i, j;
  int s = 32;  // ASCII code for a blank space
  i = 0;
  c = getchar();
  while (c != EOF && c != '\n' && i<lim) {
    // if we got a TAB, then add TABLEN spaces as array elements
    if (c == '\t') {
      for (j=0; j<TABLEN; j++) {
        arr[i] = s;
        i++;
      }
    } else {       // otherwise, add the character just read
      arr[i] = c;
      i++;
    }
    c = getchar();
  }
  arr[i] = '\0';
  return i;
}
