/* Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 */
#include <stdio.h>
#include <time.h>

int main(void) {
    // We create a very large integer array for this test. To time the two
    // methods, I've used time.h from the Standard Library. Check the book
    // "C Standard Library" by Jack Purdum.
    // After quick comparisons with different values of "seek", we see that:
    // (a)  if "seek" is present in "arr", then binsearch1 is faster
    // (b)  if "seek" is absent from "arr", then binsearch is faster
    clock_t  start, past = 0;
    int len = 100000;
    int arr[len];
    int i;
    for (i = 0; i<len; i++) {
        arr[i] = 2*i + 3;
    }
    int repetitions = 100000000;
    //int seek = 200001;  /* present in the array, near the end */
    //int seek = 23;      /* present in the array, near the beginning */
    int seek = -1;      /* not present in the array */
    int retval;

    //int j;
    //for (j = 0; j<len; j++) { printf("arr[%d] = %d\n", j, arr[j]); }

    printf("Size of array a[i]  = %d\n", len);
    printf("Array element a[i]  = 2*i + 3 where i= 0, 1, 2, ..., %d, %d\n", len-2, len-1);
    printf("Array elements a[i] = %d, %d, %d, ..., %d, %d\n", arr[0], arr[1], arr[2], arr[len-2], arr[len-1]);
    printf("Search for: %d\n", seek);
    printf("No. of times a function is invoked: %d\n", repetitions);
    printf("\n===================================================\n");

    printf("Before binsearch\n");
    int k;
    start = clock();
    for (k = 0; k < repetitions; k++) {
        retval = binsearch(seek, arr, len);
    }
    past = clock() - start; /* get the count back */
    printf("After binsearch, retval = %d\n", retval);
    printf("Time taken = %d clocks (%d seconds)", past, past/CLK_TCK);

    printf("\n===================================================\n");
    printf("Before binsearch1\n");
    start = clock();
    for (k = 0; k < repetitions; k++) {
        retval = binsearch1(seek, arr, len);
    }
    past = clock() - start; /* get the count back */
    printf("After binsearch1, retval = %d\n", retval);
    printf("Time taken = %d clocks (%d seconds)", past, past/CLK_TCK);
}

int binsearch(int x, int v[], int n) {
    /* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

int binsearch1(int x, int v[], int n) {
    /* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high && x != v[mid]) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
    }
    // At this point, we are out of the loop either because x matched
    // v[mid] or we've searched the entire array unsuccessfully.
    if (x == v[mid]) {
        return mid;
    } else {
        return -1; /* no match */
    }
}

