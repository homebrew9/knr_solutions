/* Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion.
 */
#include <stdio.h>
float convert(int fahr);

main() {
  int fhr = -100;
  int step = 10;
  int final = 100;
  printf ("%10s %10s\n", "Fahrenheit", "Celsius");
  printf ("%s %s\n", "----------", "----------");
  while (fhr <= final) {
    printf ("%10d %10.2f\n", fhr, convert(fhr));
    fhr += step;
  }
  return 0;
}

float convert(int fahr) {
  float celsius;
  celsius = (5.0/9.0)*(fahr-32.0);
  return celsius;
}
