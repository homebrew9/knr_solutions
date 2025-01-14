/* A function from Chapter 2 of KnR
 * Usage: ./atoi
 */

#include <stdio.h>

int atoi (char[]);

int main() {
  char str[] = "45673";
  printf ("String  str = %s\n", str);
  int num;
  num = atoi(str);
  printf ("Integer num = %d\n", num);
  return 0;
}

/* atoi: convert s to integer */
int atoi (char s[]) {
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}
