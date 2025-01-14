/* Section 4.5 of KnR - we are rearranging the stuff in the reverse Polish
 * calculator program in different files.
 *   calc.h  => definitions
 *   main.c  => main function and includes
 *   getop.c => getop() function and includes
 *   stack.c => push(), pop() functions, sp, val variables and includes
 *   getch.c => getch(), ungetch() functions, buf, bufp variables and includes
 */

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100   /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) { val[sp++] = f; }
    else             { printf("Error: stack full, can't push %g\n", f); }
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

