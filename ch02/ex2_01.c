/* Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#define LEN 110
int main() {
  // separaor line
  char sep[LEN];
  int i;
  for (i=0; i<LEN; i++) { sep[i] = '-'; }
  sep[i] = '\0';

  printf ("Ranges read from the limits.h file are as follows:\n");
  printf ("%s\n", sep);
  printf ("signed char             :  [-128, 127]\n");
  printf ("unsigned char           :  [   0, 255]\n");
  printf ("char                    :  if unsigned then [0, 255] else [-128, 127]\n");
  printf ("%s\n", sep);

  printf ("signed short int        :  [-32768, 32767]\n");
  printf ("unsigned short int      :  [     0, 65535]\n");
  printf ("%s\n", sep);

  printf ("signed int              :  [-2147483648, 2147483647]\n");
  printf ("unsigned int            :  [0, 4294967295]\n");
  printf ("%s\n", sep);

  printf ("signed long int         :  if __alpha__ is undefined then [-2147483648, 2147483647]\n");
  printf ("                                                otherwise [-9223372036854775808, 9223372036854775807]\n");
  printf ("unsigned long int       :  if __alpha__ is undefined then [0, 4294967295]\n");
  printf ("                                                otherwise [0, 18446744073709551615]\n");
  printf ("%s\n", sep);

  printf ("I have no clue what __alpha__ is; I simply read the content of limits.h\n");
  printf ("%s\n", sep);

  // Direct computation
  printf ("Now trying to determine the limits by direct computation.\n");
  printf ("We set variables to their bounds, print them, then overstep their bounds and print them again.\n");
  printf ("If the second printing is not as expected, then it means we've established the bounds of those variables.\n");
  printf ("%s\n", sep);

  signed char sc1, sc2;
  sc1 = -128; sc2 = 127;  // set them at their bounds
  printf ("Printing        limits of signed char [-128, 127] : [%d, %d]\n", sc1, sc2);
  sc1--; sc2++;           // overstep their bounds
  printf ("Printing beyond limits of signed char [-129, 128] : [%d, %d]\n", sc1, sc2);
  printf ("%s\n", sep);

  unsigned char usc1, usc2;
  usc1 = 0; usc2 = 255;  // set them at their bounds
  printf ("Printing        limits of unsigned char [0, 255]  : [%d, %d]\n", usc1, usc2);
  usc1--; usc2++;        // overstep their bounds
  printf ("Printing beyond limits of unsigned char [-1, 256] : [%d, %d]\n", usc1, usc2);
  printf ("%s\n", sep);

  signed short int ssi1, ssi2;
  ssi1 = -32768; ssi2 = 32767;  // set them at their bounds
  printf ("Printing        limits of signed short int [-32768, 32767] : [%d, %d]\n", ssi1, ssi2);
  ssi1--; ssi2++;               // overstep their bounds
  printf ("Printing beyond limits of signed short int [-32769, 32768] : [%d, %d]\n", ssi1, ssi2);
  printf ("%s\n", sep);

  unsigned short int ussi1, ussi2;
  ussi1 = 0; ussi2 = 65535;  // set them at their bounds
  printf ("Printing        limits of unsigned short int [0, 65535]  : [%d, %d]\n", ussi1, ussi2);
  ussi1--; ussi2++;          // overstep their bounds
  printf ("Printing beyond limits of unsigned short int [-1, 65536] : [%d, %d]\n", ussi1, ussi2);
  printf ("%s\n", sep);

  signed int si1, si2;
  si1 = -2147483648; si2 = 2147483647;  // set them at their bounds
    // the line above throws the following warning => this decimal constant is unsigned only in ISO C90
    // in gcc 4.5.3 because of the standard it follows by default. I don't know what standard it
    // follows by default. But if I compile it using -std=c99 flag, it compiles without warning.
  printf ("Printing        limits of signed int [-2147483648, 2147483647] : [%d, %d]\n", si1, si2);
  si1--; si2++;                         // overstep their bounds
  printf ("Printing beyond limits of signed int [-2147483649, 2147483648] : [%d, %d]\n", si1, si2);
  printf ("%s\n", sep);

  unsigned int usi1, usi2;
  usi1 = 0; usi2 = 4294967295;  // set them at their bounds
  printf ("Printing        limits of unsigned int [0, 4294967295]  : [%d, %d]\n", usi1, usi2);
  usi1--; usi2++;               // overstep their bounds
  printf ("Printing beyond limits of unsigned int [-1, 429496730]  : [%d, %d]\n", usi1, usi2);
  printf ("%s\n", sep);

  signed long int sli1, sli2;
  sli1 = -2147483648; sli2 = 2147483647; // set them at their bounds
  printf ("Printing        limits of signed long int [-2147483648, 2147483647] : [%d, %d]\n", sli1, sli2);
  sli1--; sli2++;                        // overstep their bounds
  printf ("Printing beyond limits of signed long int [-2147483649, 2147483648] : [%d, %d]\n", sli1, sli2);
  printf ("%s\n", sep);

  sli1 = -9223372036854775808; sli2 = 9223372036854775807; // try the larger values
  printf ("Printing        limits of signed long int [-9223372036854775808, 9223372036854775807] : [%d, %d]\n", sli1, sli2);
  printf ("Doesn't work with the larger values, so I guess __alpha__ is undefined after all.\n");
  printf ("%s\n", sep);

  unsigned long int usli1, usli2;
  usli1 = 0; usli2 = 4294967295; // set them at their bounds
  printf ("Printing        limits of unsigned long int [0, 4294967295] : [%d, %d]\n", usli1, usli2);
  usli1--; usli2++;                        // overstep their bounds
  printf ("Printing        limits of unsigned long int [0, 4294967296] : [%d, %d]\n", usli1, usli2);

  return 0;
}
