/* Section 4.5 of KnR - we are rearranging the stuff in the reverse Polish
 * calculator program in different files.
 *   calc.h  => definitions
 *   main.c  => main function and includes
 *   getop.c => getop() function and includes
 *   stack.c => push(), pop() functions, sp, val variables and includes
 *   getch.c => getch(), ungetch() functions, buf, bufp variables and includes
 */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') { ; }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;  /* not a number */
    }
    i = 0;
    if (isdigit(c)) {
        /* collect integer part */
        while (isdigit(s[++i] = c = getch())) { ; }
    }
    if (c == '.') {
        /* collect fraction part */
        while (isdigit(s[++i] = c = getch())) { ; }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

