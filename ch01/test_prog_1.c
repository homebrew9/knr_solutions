#include <stdio.h>
int main() {
  char arr[10];
  arr[0] = 'a';
  arr[1] = 'b';
  arr[2] = 'c';
  arr[3] = 'd';
  arr[4] = 'e';
  arr[5] = '\0';
  printf ("%s\n", arr);
  //
  arr[0] = 'A';
  arr[1] = 'B';
  printf ("%s\n", arr);
  return 0;
}
