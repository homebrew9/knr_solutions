/* Section 4.5 of KnR - we are rearranging the stuff in the reverse Polish
 * calculator program in different files.
 *   calc.h  => definitions
 *   main.c  => main function and includes
 *   getop.c => getop() function and includes
 *   stack.c => push(), pop() functions, sp, val variables and includes
 *   getch.c => getch(), ungetch() functions, buf, bufp variables and includes
 */

#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include "calc.h"
#define MAXOP  100  /* max size of operand or operator */

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                printf("\tIn case NUMBER: we got type, s = [%d], [%s]\n", type, s);
                push(atof(s));
                break;
            case '+':
                printf("\tIn case +     : we got type, s = [%d], [%s]\n", type, s);
                push(pop() + pop());
                break;
            case '*':
                printf("\tIn case *     : we got type, s = [%d], [%s]\n", type, s);
                push(pop() * pop());
                break;
            case '-':
                printf("\tIn case -     : we got type, s = [%d], [%s]\n", type, s);
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                printf("\tIn case /     : we got type, s = [%d], [%s]\n", type, s);
                op2 = pop();
                if (op2 != 0.0) { push(pop() / op2);               }
                else            { printf("Error: zero divisor\n"); }
                break;
            case '\n':
                printf("\tIn case nl    : we got type, s = [%d], [%s]\n", type, s);
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

