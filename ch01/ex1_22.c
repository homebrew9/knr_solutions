/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 *
 * Usage: ./ex1_22 < voltaire.txt
 *
 */
#include <stdio.h>
#define FOLDLEN 80

int main() {
  int c;
  int charcount = 0;
  int in = 0; // in : 1 = traversing through a word; 0 = "outside" a word
  int last_word_pos = 0;
  int start_of_blank_line = 0;

  while ((c = getchar()) != EOF) {
    charcount++;
    if (c == ' ' || c == '\t') {
      if (in == 1) { in = 0; }  // we are "outside" a word
    } else if (c == '\n') {
      if (start_of_blank_line == 0) {
        start_of_blank_line = 1;
      } else if (start_of_blank_line == 1) {
        start_of_blank_line = 0;
        charcount = 0;
      }
    } else {
      if (in == 0) {
        in = 1;   // we are "inside" a word
        last_word_pos = charcount;
      }
      if (start_of_blank_line == 1) { start_of_blank_line = 0; }
    }

    if (charcount == FOLDLEN) {
      printf ("%c|%d|%d|\n", c, charcount, last_word_pos);
      charcount = 0;
    } else {
      printf ("%c", c);
    }
  }
  return 0;
}
