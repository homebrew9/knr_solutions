#include <stdio.h>

main() {
  // A quick test to see how character arrays are formed.
  char arr[10];
  int i = 0;
  
  // Assign
  for (i=0; i<=10; i++) {
    arr[i] = i+97;
  }
  
  // Print
  for (i=0; i<=10; i++) {
    printf ("%c", arr[i]);
  }
  printf ("\n=====\n");
  printf ("%s\n", arr);
}
