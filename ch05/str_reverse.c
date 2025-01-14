/* A short program to see if reversal of string can work with just two pointers. */
#include <stdio.h>
#define MAXLEN 100

int main(void) {
    //char str[MAXLEN] = "Supercalifragilisticexpialidocious";
    char str[MAXLEN] = "The woods are lovely, dark and deep";
    int i = 0;

    printf("str = [%s]\n", str);

    char *lptr = str;

    /* Slide down *rptr all the way to the end of the string */
    char *rptr = str;
    while (*rptr) {
        //printf("[%4d] - [%p] - [%3u] - [%c]\n", i++, rptr, *rptr, *rptr);
        *rptr++;
    }
    *rptr--;

    /* Now, let's slide *rptr back to the beginning and *lptr to the right
     * and see how their memory locations compare. We want to see where they
     * cross their locations, which is approximately the midpoint of the
     * string. If the string length is odd, the pointers meet at the midpoint.
     * If the string length is even, the pointer cross each other somewhere
     * near the middle.
     */
    printf("------------------------------------------------------------------------------------\n");
    i = 0;
    while (*lptr) {
        printf("[%4d] - [%p] - [%3u] - [%c]    |    [%p] - [%3u] - [%c]    |    [%3d]\n", i++, lptr, *lptr, *lptr, rptr, *rptr, *rptr, (rptr - lptr));
        *lptr++;
        *rptr--;
    }

    /* Having seen the behavior of the pointers above, it is easy to deduce a technique to
     * reverse a string in place, simply by using right and left pointers. We set up the
     * pointers again, slide the right pointer and then write a loop that does the job.
     */

    char *lp = str;
    char *rp = str;
    while (*rp) { *rp++; }
    *rp--;

    printf("------------------------------------------------------------------------------------\n");
    int temp;
    for ( ; rp - lp > 0; *lp++, *rp-- ) {
        temp = *lp;
        *lp = *rp;
        *rp = temp;
    }

    printf("str = [%s]\n", str);

    return 0;
}

