/* Modify the temperature conversion program to print the table in reverse
 * order, that is, from 300 degrees to 0.
 */
#include <stdio.h>
main() {
  int min_fahr = 0;
  int max_fahr = 300;
  int step = 10;
  printf ("+==================+\n");
  printf ("| Using while loop |\n");
  printf ("+==================+\n\n");
  float cels;
  printf ("%-10s\t%-10s\n", "Fahrenheit", "Celsius");
  printf ("%s\t%-s\n", "----------", "----------");
  while (max_fahr >= min_fahr) {
    cels = (5.0/9.0)*(max_fahr-32.0);
    printf ("%10d\t%10.2f\n", max_fahr, cels);
    max_fahr -= step;
  }
  // --------------------------------------------------
  printf ("+==================+\n");
  printf ("| Using for loop |\n");
  printf ("+==================+\n\n");
  printf ("%-10s\t%-10s\n", "Fahrenheit", "Celsius");
  printf ("%s\t%-s\n", "----------", "----------");
  max_fahr = 300;       // reset max_fahr
  int i;
  for (i=max_fahr; i>=min_fahr; i-=step) {
    cels = (5.0/9.0)*(i - 32.0);
    printf ("%10d\t%10.2f\n", i, cels);
  }
}

