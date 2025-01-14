#include <stdio.h>

int main(void) {
    int arr[10] = {10, 21, 34, 56, 89, 99, 104, 349, 567, 873};
    int seek = 56;
    int retval;
    printf("Before binsearch\n");
    printf("Search for: %d\n", seek);
    int i;
    for (i = 0; i<10; i++) { printf("arr[%d] = %d\n", i, arr[i]); }
    retval = binsearch(seek, arr, 10);
    printf("After binsearch, retval = %d\n", retval);
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

