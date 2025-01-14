/* Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab. When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 * Ans: The single blank should be given preference, because a tab could map to
 *      different number of blanks in different editors.
 * Usage: ./ex1_21 < spaces_to_tabs.txt
 */

#include <stdio.h>
#define MAX 100
#define TABLEN 8

int read_line (char []);

int main() {
  char line[MAX];
  int len;
  while ( (len = read_line (line)) > 0) {
    printf ("%s\n", line);
  }
  return 0;
}

int read_line (char input[]) {
  int i, c;
  int consecutive_spaces = 0;
  int j;
  i = 0;
  c = getchar();
  while (c != EOF && c != '\n' && i<MAX) {
    if (c == ' ') {
      consecutive_spaces++;
      if (consecutive_spaces == TABLEN) {
        input[i] = '\t';
        i++;
        consecutive_spaces = 0;
      }
    } else {
      if (consecutive_spaces > 0) {
        for (j=0; j<consecutive_spaces; j++) { input[i] = ' '; i++; }
        consecutive_spaces = 0;
      }
      input[i] = c;
      i++;
    }
    c = getchar();
  }
  input[i] = '\0';
  return i;
}
