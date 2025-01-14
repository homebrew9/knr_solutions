/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 * Usage: ./ex1_13 < sample_file.txt
 *        ./ex1_13 < chekhov_the_bet.txt
 *        ./ex1_13 < ohenry_gift_of_magi.txt
 *        ./ex1_13 < poe_the_gold_bug.txt
 * Notes:
 *   I remember writing the "vertical bar" program a few years ago, but it
 *   did not have scale sizing. The current program sizes the scale as per
 *   the max wordcount. I'll try out the vertical bar program some other time.
 */
#include <stdio.h>
main () {
  int c, i;
  int nw = 0;
  int wlen = 0;
  // For the integer array wordlen -
  // index 0 = word-lengths  0 to 4
  // index 1 = word-lengths  5 to 9
  // index 2 = word-lengths 10 to 14
  // index 3 = word-lengths 15 to 19
  // ... and so on ...
  int wordlen[10];
  for (i = 0; i < 10; i++) {
    wordlen[i] = 0;
  }
  c = getchar();
  while (c != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      ++nw;
      // printf ("Word-length, index = %d, %d\n", wlen, wlen/5);
      ++wordlen[wlen/5];
      wlen = 0;
    } else {
      ++wlen;
    }
    c = getchar();
  }
  // printf ("Total word count = %d\n", nw);
  // We determine the max_count first.
  int max_count = 0;  // max array element; max wordcount for any length freq
  for (i = 0; i < 10; i++) {
    if (wordlen[i] > max_count) { max_count = wordlen[i]; }
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
  // we start with the histogram array - wlen
  int j, k;
  // For the wlen array, the correspondence between array index and wordlength frequencies is as follows:
  // 0=>(0..4); 1=>(5,9); 2=>(10,14); 3=>(15,19); 4=>(20,24); 5=>(25,29); 6=>(30,34); 7=>(35,39); 8=>(40,44); 9=>(45,49)
  for (i=0; i < 10; i++) {
    printf ("%11s\n", "|");
    printf ("%3d - %3d +", i*5, i*5+4);
    for (k=0; k < wordlen[i]; k += scale_factor) {
      printf ("#");
    }
    printf ("\n");
    //printf ("%d\n", arr[i]); 
  }
}

