/* Section 4.5 of KnR - we are rearranging the stuff in the reverse Polish
 * calculator program in different files.
 *   calc.h  => definitions
 *   main.c  => main function and includes
 *   getop.c => getop() function and includes
 *   stack.c => push(), pop() functions, sp, val variables and includes
 *   getch.c => getch(), ungetch() functions, buf, bufp variables and includes
 */

/* Modify getop so that it doesn't need to use ungetch. Hint: use an internal
 * static variable.
 * (An internal static variable holds its value even between function calls.)
 */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    static int buf_char;
    buf_char = '\0';

    int i, c;
    do {
        if (buf_char == '\0') {
            s[0] = c = getch();
        } else {
            s[0] = c = buf_char;
            buf_char = '\0';
        }
    } while (c == ' ' || c == '\t');

    /* while ((s[0] = c = getch()) == ' ' || c == '\t') { ; } */

    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;  /* not a number */
    }
    i = 0;
    if (isdigit(c)) {
        /* collect integer part */
        do {
            if (buf_char == '\0') {
                s[++i] = c = getch();
            } else {
                s[++i] = c = buf_char;
                buf_char = '\0';
            }
        } while (isdigit(c));

        /* while (isdigit(s[++i] = c = getch())) { ; } */
    }
    if (c == '.') {
        /* collect fraction part */
        do {
            if (buf_char == '\0') {
                s[++i] = c = getch();
            } else {
                s[++i] = c = buf_char;
                buf_char = '\0';
            }
        } while (isdigit(c));

        /* while (isdigit(s[++i] = c = getch())) { ; } */

    }
    s[i] = '\0';
    if (c != EOF) {
        //ungetch(c);
        buf_char = c;
    }
    return NUMBER;
}

