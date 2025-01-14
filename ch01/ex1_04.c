/* Write a program to print the corresponding Celsius to Fahrenheit table.
 */
#include <stdio.h>
main() {
  int min_cels = -100;
  int max_cels =  200;
  int incr = 10;
  float fahr;
  printf ("%-10s\t%-10s\n", "Celsius", "Fahrenheit");
  printf ("%s\t%-s\n", "----------", "----------");
  while (min_cels <= max_cels) {
    fahr = (9.0/5.0)* min_cels + 32.0;
    printf ("%10d\t%10.2f\n", min_cels, fahr);
    min_cels += incr;
  }
}

