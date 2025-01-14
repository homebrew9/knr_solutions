/* The recursive printd function from Section 4.10 of KnR. It accepts an
 * integer and prints it as a character string. A similar problem was solved
 * earlier, but it generated a reversed string, which was then reversed again.
 * This time, the printd function is recursive and does not require reversing
 * the generated string.
 */
#include <stdio.h>

void printd(int n);

int main(void) {
    int p = 456891;
    printf("Before call: p = %d\n", p);
    printf("After call : p = ");
    printd(p);
    printf("\n");

    int q = -2359;
    printf("\nBefore call: q = %d\n", q);
    printf("After call : q = ");
    printd(q);
    printf("\n");

    int r = 667800;
    printf("\nBefore call: r = %d\n", r);
    printf("After call : r = ");
    printd(r);
    printf("\n");

    return 0;
}

void printd(int n) {
    /* printd: print n in decimal */
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

