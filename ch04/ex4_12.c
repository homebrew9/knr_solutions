/* Adapt the ideas of printd to write a recursive version of itoa, that is,
 * convert an integer into a string by calling a recursive routine.
 */
#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void itoa_rcr(int n, char s[]);

int main(void) {
    int p = -12345600;
    char s[MAXLEN];
    printf("Before call: p = [%d], s = [%s]\n", p, s);
    itoa_rcr(p, s);
    printf("After call : p = [%d], s = [%s]\n", p, s);
    return 0;
}

void itoa_rcr(int n, char s[]) {
    /* convert integer to string in a recursive function */
    if (n < 0) {
        /* putchar('-'); */
        s[0] = '-';
        s[strlen(s)] = '\0';
        n = -n;
    }
    if (n / 10) {
        itoa_rcr(n / 10, s);
    }
    /* putchar(n % 10 + '0'); */
    s[strlen(s)] = n % 10 + '0';
    s[strlen(s)+1] = '\0';
}

