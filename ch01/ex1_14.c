/* Write a program to print a histogram of the frequencies of different
 * characters in its input.
 * Usage: ./ex1_13 < sample_file.txt
 *        ./ex1_13 < chekhov_the_bet.txt
 *        ./ex1_13 < ohenry_gift_of_magi.txt
 *        ./ex1_13 < poe_the_gold_bug.txt
 */
#include <stdio.h>
main () {
  int c, i;
  // For the integer array cfreq -
  // index 0 = frequency of character 'a'
  // index 1 = frequency of character 'b'
  // index 2 = frequency of character 'c'
  // index 3 = frequency of character 'd'
  // ... and so on ...
  int cfreq[26];
  for (i = 0; i < 26; i++) {
    cfreq[i] = 0;
  }
  c = getchar();
  while (c != EOF) {
    if (c >= 'a' && c <= 'z') {
      cfreq[c - 'a']++;
    } else if (c >= 'A' && c <= 'Z') {
      cfreq[c - 'A']++;
    }
    c = getchar();
  }
  // We determine the max_count first.
  int max_count = 0;  // max array element; max wordcount for any length freq
  for (i = 0; i < 10; i++) {
    if (cfreq[i] > max_count) { max_count = cfreq[i]; }
  }
  // printf ("max_count = %d\n", max_count);
  // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // We now start the section for generation of the vertical graph. We define
  // a few variables to determine the min/max points and the scale factor
  // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  int min_point = 0;     // the leftmost point on the horizontal scale; it is always 0
  int max_point = 50;    // the rightmost point on the horizontal scale
  int scale_factor = 0;  // the worth of each point in the horizontal scale
  int quotient = max_count/max_point;
  int remainder = max_count % max_point;
  // keep looping until we find the correct max_point
  while (! ((quotient == 0) || (quotient == 1 && remainder == 0))) {
    max_point *= 10;
    quotient = max_count/max_point;
    remainder = max_count % max_point;
  }
  scale_factor = max_point/50;
  // print the horizontal ruler
  int iter = min_point;  // iterator variable to print ruler
  printf ("%11s", "0");
  iter += 10*scale_factor;
  while (iter <= max_point) {
    printf ("%10d", iter);
    iter += 10*scale_factor;
  }
  printf ("\n");
  // print the horizontal ruler
  iter = min_point;
  printf ("%11s", "+");
  iter += 10*scale_factor;
  while (iter <= max_point) {
    printf ("---------+");
    iter += 10*scale_factor;
  }
  printf ("\n");
  // print the vertical scale
  // we start with the histogram array - cfreq
  int j, k;
  // For the cfreq array, the correspondence between array index and wordlength frequencies is as follows:
  // 0=>(0..4); 1=>(5,9); 2=>(10,14); 3=>(15,19); 4=>(20,24); 5=>(25,29); 6=>(30,34); 7=>(35,39); 8=>(40,44); 9=>(45,49)
  for (i=0; i < 26; i++) {
    printf ("%9c +", 'a'+i);
    for (k=0; k < cfreq[i]; k += scale_factor) {
      printf ("*");
    }
    printf ("\n");
  }
}

