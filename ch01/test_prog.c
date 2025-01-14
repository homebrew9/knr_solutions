/* Just a test program */
#include <stdio.h>
main () {
  int min_point = 0;     // min_point is always 0
  int max_count = 47;
  int max_point = 50;
  int iter = min_point;  // iterator variable to print ruler
  int scale_factor = 0;
  int quotient = max_count/max_point;
  int remainder = max_count % max_point;
  // keep looping until we find the correct max_point
  while (! ((quotient == 0) || (quotient == 1 && remainder == 0))) {
    max_point *= 10;
    quotient = max_count/max_point;
    remainder = max_count % max_point;
  }
  scale_factor = max_point/50;
  // printf ("max_count = %d\n", max_count);
  // printf ("min_point = %d\n", min_point);
  // printf ("max_point = %d\n", max_point);
  // printf ("scale_factor = %d\n", scale_factor);
  // print the horizontal markings
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
  // we start with the histogram array first
  int i, j, k;
  int arr[10];
  arr[0] = 47; arr[1] = 34; arr[2] = 29; arr[3] = 19; arr[4] = 13; arr[5] = 8; arr[6] = 5; arr[7] = 3; arr[8] = 0; arr[9] = 0;
  // 0=>(0..4); 1=>(5,9); 2=>(10,14); 3=>(15,19); 4=>(20,24); 5=>(25,29); 6=>(30,34); 7=>(35,39); 8=>(40,44); 9=>(45,49)
  for (i=0; i < 10; i++) {
    printf ("%11s\n", "|");
    printf ("%3d - %3d +", i*5, i*5+4);
    for (k=0; k < arr[i]; k += scale_factor) {
      printf ("#");
    }
    printf ("\n");
    //printf ("%d\n", arr[i]); 
  }
}
