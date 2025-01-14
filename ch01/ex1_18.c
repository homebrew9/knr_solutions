/* Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 * Usage: ./ex1_18 < sample_file_3.txt
 */
#include <stdio.h>
#define MAX 100

int main() {
  int c, i, j, end, first_ws, atleast_one_non_ws;
  // a very limited solution; we assume that each input line has at the most
  // 100 characters
  char line[MAX];
  first_ws = i = atleast_one_non_ws = 0;
  while ((c = getchar()) != EOF) {
    line[i] = c;
    ++i;
    if (c == ' ' || c == '\t') {
      if (first_ws == 0) {
        first_ws = i;
      }
    } else if (c == '\n') {
      // At this point, if first_ws > 0, then print the array "line"
      // till index (first_ws - 1) else print till index i
      if (atleast_one_non_ws == 1) {
        if (first_ws > 0) {
          for (j=0; j<first_ws-1; j++) { printf ("%c", line[j]); }
          printf ("\n");
        } else {
          line[i] = '\0';
          printf ("%s", line);
        }
      }
      first_ws = i = atleast_one_non_ws = 0;
    } else {
      first_ws = 0;
      atleast_one_non_ws = 1;
    }
  }
  return 0;
}
