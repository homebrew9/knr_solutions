/* Modify the temperature conversion program to print a heading above the table
 */
#include <stdio.h>
main() {
  int min_fahr = -100;
  int max_fahr =  200;
  int incr = 10;
  float cels;
  printf ("%-10s\t%-10s\n", "Fahrenheit", "Celsius");
  printf ("%s\t%-s\n", "----------", "----------");
  while (min_fahr <= max_fahr) {
    cels = (5.0/9.0)*(min_fahr-32.0);
    printf ("%10d\t%10.2f\n", min_fahr, cels);
    min_fahr += incr;
  }
}


