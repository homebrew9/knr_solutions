/* As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 *
 * Invocation: ./getint < sample.txt
 *           : ./getint < sample1.txt
 *           : (echo 1234; echo +789; echo -30098) | ./getint
 *           : (echo 1234; echo +; echo -30098) | ./getint
 *
 */
#include <stdio.h>
#include <ctype.h>
#define SIZE 20

int getint(int *);
int getch(void);
void ungetch(int);

int main(void) {
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
        ;
    }
    printf("Return value of getint = %d\n", getint(&array[n]));
    int i;
    for (i = 0; i < n; i++) {
        printf("i = %d, array element = %d\n", i, array[i]);
    }
}

int getint(int *pn) {
    /* getint: get next integer from input into *pn */
    int c, sign;
    while (isspace(c = getch())) {    /* skip white space */
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);    /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch( (sign == -1) ? '-' : '+' );
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

/* ============================================================== */

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void) {
    /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    /* push character back on input */
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}


