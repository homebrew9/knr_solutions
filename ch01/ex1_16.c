/* Revise the main routine of the longest line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of
 * the text.
 * Usage: ./ex1_16 < many_blanks.txt
 * Notes: I will write my own program here. The K&R program is elsewhere in the
 *        current directory.
 *        If maxline looks like this:
 *
 *        ABCDEF\n
 *
 *        then this program calculates the length as 7. And since Windows has
 *        '\r\n' as end-of-line character, the maxlength in case of Windows file
 *        would be 8.
 */
#include <stdio.h>
#define MAX 25
void copy (char from[], char to[]);

main() {
  int maxlen  = 0;
  int linelen = 0;
  int c, i, j;
  char line[MAX];
  char longest[MAX];
  i = 0;
  while ((c = getchar()) != EOF) {
    // printf ("=========================================================\n");
    // printf ("Char read = %c\n", c);
    linelen++;
    // printf ("linelen, i = %d, %d\n", linelen, i);
    if (c == '\n') {
      if (linelen > maxlen) {
        maxlen = linelen;
        line[i] = '\0';
        // printf ("BEFORE copy; maxlen, i, line = %d, %d, %s\n", maxlen, i, line);
        copy (line, longest);
        // printf ("AFTER  copy; 1st char of longest         = %c\n", longest[0]);
        // printf ("AFTER  copy; longest = %s\n", longest);
      }
      linelen = 0;
      i = 0;
    } else if (i < MAX-1) {
      // printf ("Inside IF, before array push; i, MAX, c = %d, %d, %c\n", i, MAX, c);
      line[i] = c;
      // printf ("Inside IF,  after array push; 1st char, last char = %c, %c\n", line[0], line[i]);
      // printf ("line = %s\n", line);
      i++;
    }
  }
  printf ("Max line len = %d\n", maxlen);
  printf ("This program can capture only up to %d chars of the longest line. It is as follows:\n", MAX);
  printf ("%s\n", longest);
  return 0;
}

void copy (char from[], char to[]) {
  int c, i;
  i = 0;
  c = from[i];
  while (c != '\0') {
    to[i] = from[i];
    i++;
    c = from[i];
  }
  to[i] = '\0';
}
