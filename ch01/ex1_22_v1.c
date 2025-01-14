/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 *
 * Usage: ./ex1_22_v1 < voltaire.txt
 *
 * Problems: (1) Goes into an infinite loop in case of "sample_file_4.txt"
 *           (2) Does not align "ohenry_gift_of_magi.txt" if FOLDLEN=40
 *
 */
#include <stdio.h>
#define FOLDLEN 40
#define MAXLINE 1000

int read_line (char[], int);

int main() {
  char line[MAXLINE];
  int len, i;
  int startpos = 0;
  int endpos, mod_endpos;
  int fold_code = 0; // 1 means "correct folding"; 0 means "incorrect folding"

  while ((len = read_line(line, MAXLINE)) > 0) {
    do {
      endpos = (startpos + FOLDLEN) < len ? (startpos + FOLDLEN) : len;
      if (line[endpos-1] == ' ' || line[endpos-1] == '\t' || line[endpos] == ' ' || line[endpos] == '\t') {
        fold_code = 1;
      } else {
        fold_code = 0;
      }
      // In case fold_code = 0, find out the modified end position (mod_endpos)
      mod_endpos = endpos;
      if (fold_code == 0 && (endpos - startpos) >= FOLDLEN) {
        while (line[mod_endpos] != ' ' && line[mod_endpos] != '\t') { mod_endpos--; }
        if (mod_endpos < startpos) {
          // The entire line is without a whitespace; reset the modified end-position
          mod_endpos = endpos;
        }
      }
      printf ("%03d-%03d-%d:%03d|", startpos, endpos, fold_code, mod_endpos);

      for (i = startpos; i < mod_endpos; i++) {
        printf ("%c", line[i]);
      }
      if (i < len) { printf ("\n"); }
      startpos += FOLDLEN - (endpos - mod_endpos);
      if (line[startpos] == ' ' || line[startpos] == '\t') { startpos++; }
    } while (startpos < len);
    startpos = 0;
  }

  return 0;
}

int read_line (char input[], int max) {
  int c;
  int i = 0;

  c = getchar();
  while (c != EOF && c != '\n' && i < max) {
    input[i] = c;
    i++;
    c = getchar();
  }
  // The following if branch handles a blank line (one that has nothing but a
  // newline in it. It also handles cases that exit out of the while loop due
  // to a newline being encountered.
  if (c == '\n') { input[i] = c; i++; }
  input[i] = '\0';
  return i;
}
