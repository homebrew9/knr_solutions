/* A program to generate consecutive binary numbers of 3 digits. We use a
 * simple recursive function that increments digits of an array from the
 * right to the left and stops when it cannot increment any more. Each array
 * element is a bit (0 or 1). As Mark Jason Dominus says: "This algorithm should
 * sound familiar, because you learned it a long time ago. It's exactly the same
 * as the algorithm you use to **count**."
 * Usage:
 *     ./gen_bin N
 *     where N between 2 and 10; if omitted, N = 4
 * By: r2d2
 * On: 7/28/2015
 */
#include <stdio.h>
#define MAXSIZE 20 
#define DEFAULT_SIZE 4

void initialize(int *b, int lim);
void printarr(int *b, int lim);
void permute(int *b, int lim);

int main(int argc, char *argv[]) {
    int size = DEFAULT_SIZE;
    if (argc > 1) {
        size = atoi(*++argv);
        if (size <= 0 || size > MAXSIZE) {
            printf("Usage: ./gen_bin N\n");
            printf("where N between 1 and %d; if omitted, N = %d\n", MAXSIZE, DEFAULT_SIZE);
            return(1);
        }
    }
    int bits[size];
    initialize(bits, size);
    permute(bits, size);
    return(0);
}

void initialize(int *b, int lim) {
    while (lim-- > 0)
        *b++ = 0;
}

void printarr(int *b, int lim) {
    while (lim-- > 0)
        printf("%d", *b++);
    printf("\n");
}

void permute(int *b, int lim) {
    printarr(b, lim);
    int i;
    int all_set = 1;
    for (i = lim-1 ; i >= 0 ; i--) {
        if ( b[i] == 0 ) {
            b[i] = 1;
            all_set = 0;
            break;
        } else if ( b[i] == 1 ) {
            b[i] = 0;
        }
    }
    if (all_set)
        return;
    else
        permute(b, lim);
}

