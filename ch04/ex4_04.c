/* Add commands to print the top element of the stack without popping, to
 * duplicate it, and to swap the top two elements. Add a command to clear
 * the stack.
 * Usage samples:
 *         $ ./ex4_04
 *         2 3 + p c 7 7 *
 *                 Top of stack = 5
 *                 Clearing the stack
 *                 Value = 49
 *         2 3 + p c 7 8 s /
 *                 Top of stack = 5
 *                 Clearing the stack
 *                 Swapping top two elements of stack
 *                 Value = 1.1428571
 *         2 3 + p c 7 8 /
 *                 Top of stack = 5
 *                 Clearing the stack
 *                 Value = 0.875
 *         2 3 + p c 113 355 s /
 *                 Top of stack = 5
 *                 Clearing the stack
 *                 Swapping top two elements of stack
 *                 Value = 3.1415929
 *         2 3 + p d * p d * p 17 /
 *                 Top of stack = 5
 *                 Duplicating the top element of stack
 *                 Top of stack = 25
 *                 Duplicating the top element of stack
 *                 Top of stack = 625
 *                 Value = 36.764706
 *         
 *         [46]+  Stopped                 ./ex4_04
 * 
 */

#include <stdio.h>
#include <stdlib.h>  /* for atof() */

#define MAXOP  100  /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* ---------------------------------------------------------------------------- */
#define MAXVAL 100   /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
/* ---------------------------------------------------------------------------- */

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];
    int hi;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                //printf("\t\tIn case NUMBER: we got type, s = [%d], [%s]\n", type, s);
                push(atof(s));
                break;
            case '+':
                //printf("\t\tIn case +     : we got type, s = [%d], [%s]\n", type, s);
                push(pop() + pop());
                break;
            case '*':
                //printf("\t\tIn case *     : we got type, s = [%d], [%s]\n", type, s);
                push(pop() * pop());
                break;
            case '-':
                //printf("\t\tIn case -     : we got type, s = [%d], [%s]\n", type, s);
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                //printf("\t\tIn case /     : we got type, s = [%d], [%s]\n", type, s);
                op2 = pop();
                if (op2 != 0.0) { push(pop() / op2);               }
                else            { printf("Error: zero divisor\n"); }
                break;
            case '%':
                //printf("\t\tIn case %     : we got type, s = [%d], [%s]\n", type, s);
                op2 = pop();
                /* The modulus operator works only with integers, so one option
                 * is to convert both operands to ints and work with that and option
                 * two is to throw an error if any operand is not an int. Let's go
                 * with first option.
                 */
                int q = op2;
                if (op2 != 0.0) {
                    int p = pop();
                    push(p % q);
                } else {
                    printf("Error: zero divisor\n");
                }
                break;
            case 'p':
                //printf("\t\tIn case p     : we got type, s = [%d], [%s]\n", type, s);
                hi = sp;
                printf("\tTop of stack = %.8g\n", val[--hi]);
                break;
            case 'd':
                //printf("\t\tIn case d     : we got type, s = [%d], [%s]\n", type, s);
                printf("\tDuplicating the top element of stack\n");
                int h = sp;
                push(val[--h]);
                break;
            case 's':
                //printf("\t\tIn case s     : we got type, s = [%d], [%s]\n", type, s);
                printf("\tSwapping top two elements of stack\n");
                double last = pop();
                double penultimate = pop();
                push(last);
                push(penultimate);
                break;
            case 'c':
                //printf("\t\tIn case c     : we got type, s = [%d], [%s]\n", type, s);
                printf("\tClearing the stack\n");
                while (sp > 0) {
                    pop();
                }
                break;
            case '\n':
                //printf("\t\tIn case nl    : we got type, s = [%d], [%s]\n", type, s);
                printf("\tValue = %.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------- */
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;
    int oprnd;
    i = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t') { ; }

    if (!isdigit(c) && c != '.') {
        /* if "-" is followed by a digit, it's a negative number.
         * if "-" is followed by a whitespace of EOF, it's an operand
         * everything else is also assumed to be an operand.
         */
        if (c == '-') {
            oprnd = c;
            c = getch();
            if (!isdigit(c)) {
                ungetch(c);
                s[++i] = '\0';
                return oprnd;
            } else {
                /* if we've reached here, it's a negative number */
                s[++i] = c;
            }
        } else {
            s[++i] = '\0';
            return c;
        }
    }

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

/* ---------------------------------------------------------------------------- */
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

