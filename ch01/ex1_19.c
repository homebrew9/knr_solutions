/* Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.
 *
 * Usage: ./ex1_19.c < sample_file_1.txt
 *        ./ex1_19.c < ohenry_gift_of_magi.txt
 *
 */
#include <stdio.h>
#define MAX 100
// int get_line (char line[], int lim);
int read_line (char arr[], int lim);
void reverse (char orig[], char reversed[], int size);

int main() {
  char line[MAX];
  char reversed_line[MAX];
  int len;

  // len = get_line (line, MAX);
  while ((len = read_line (line, MAX)) > 0) {
    reverse (line, reversed_line, len);
    printf ("%s\n", reversed_line);
  }
}

// int get_line (char arr[], int lim) {
//   int i=0;
//   int max=7;
//   for (i=0; i<max; i++) {
//     arr[i] = i+97;
//   }
//   arr[i] = '\0';
//   return i;
// }

int read_line (char arr[], int lim) {
  int c, i;
  i = 0;
  c = getchar();
  while (c != EOF && c != '\n' && i<lim) {
    arr[i] = c;
    i++;
    c = getchar();
  }
  arr[i] = '\0';
  return i;
}

void reverse (char orig[], char reversed[], int size) {
  int i = 0;
  while (orig[i] != '\0') {
    reversed[size - 1 - i] = orig[i];
    i++;
  }
  reversed[i] = '\0';
}

