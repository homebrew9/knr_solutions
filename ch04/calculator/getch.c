/* Section 4.5 of KnR - we are rearranging the stuff in the reverse Polish
 * calculator program in different files.
 *   calc.h  => definitions
 *   main.c  => main function and includes
 *   getop.c => getop() function and includes
 *   stack.c => push(), pop() functions, sp, val variables and includes
 *   getch.c => getch(), ungetch() functions, buf, bufp variables and includes
 */

#include <stdio.h>
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

