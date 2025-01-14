/* Write a loop equivalent to the for loop above without using && or ||
 *
 * The loop given in the textbook is for the getline function, as follows:
 *
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) { s[i] = c; }
 *
 * Usage: ./ex2_02 < sample_file_4.txt
 *        ./ex2_02 < sample_file_5.txt
 *        ./ex2_02 < ohenry_gift_of_magi.txt
 *
 * Issues: (1) if MAXLINE=80, then it prints a random char at the end of each
 *             line for the input file "sample_file_5.txt"
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
int readline (char[], int);

int main() {
  char arr[MAXLINE];
  int len;
  while ( (len = readline (arr, MAXLINE)) > -1) {
    printf ("%d|%s\n", len, arr);
  }
  return 0;
}

int readline (char s[], int lim) {
  int i = 0;
  int c;

  c = getchar();
  while (c != EOF) {
    s[i] = c;
    if (c == '\n') { break; }
    ++i;
    if (i == lim) { break; }
    c = getchar();
  }
  s[i] = '\0';
  if (c == EOF) {
    return -1;     // true end of file and not just a blank line
  } else {
    return i;      // i = 0 for blank line, > 1 otherwise
  }
}
