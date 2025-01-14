/* Section 4.5 of KnR - we are rearranging the stuff in the reverse Polish
 * calculator program in different files.
 *   calc.h  => definitions
 *   main.c  => main function and includes
 *   getop.c => getop() function and includes
 *   stack.c => push(), pop() functions, sp, val variables and includes
 *   getch.c => getch(), ungetch() functions, buf, bufp variables and includes
 */

/* A program to evaluate reverse Polish expressions, from Section 4.3 of KnR */
#define NUMBER '0'  /* signal that a number was found */

void push(double);
double pop(void);
int getop(char []);

int getch(void);
void ungetch(int);

