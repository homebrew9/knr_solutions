/* Add commands for handling variables. (It's easy to provide twenty-six
 * variables with single-letter names.) Add a variable for the most recently
 * printed value.
 * Variables will be in upper case only and 26 in number.
 * Variable assignment examples: "A=3" or "A=3 B=-0.678 C=4.5"
 * No spaces around the "=" operator.
 */

#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <string.h>
#include <math.h>

#define MAXOP  100  /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define FUNCTION '1'  /* signal that a function was found */
#define VARASSIGN '2' /* signal that variable(s) are to be assigned */
#define VARIABLE '3' /* signal that variable is to he pushed to stack */
#define MAXVARS 26 /* we allow up to 26 variables */

int getop(char []);
void push(double);
double pop(void);

/* ---------------------------------------------------------------------------- */
#define MAXVAL 100   /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
/* ---------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------- */
/* Kind of messy to use two parallel arrays for storing variable information, but
 * higher level data structures have not been explained at this point.
 */
double var[MAXVARS];
int setvar[MAXVARS];
void assignvar(char str[]);
/* ---------------------------------------------------------------------------- */

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];
    int hi;

    /* set the bits in setvar array to 0 initially. As variables are declared and
     * assigned, we use var and setvar in parallel and set the setvar index to 1.
     */
    int i;
    for(i = 0; i < MAXVARS; i++) {
        var[i] = 0.0;
        setvar[i] = 0;
   }

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
            case FUNCTION:
                //printf("\t\tIn case FN    : we got type, s = [%d], [%s]\n", type, s);
                if (strcmp(s, "sin") == 0) {
                    push(sin(pop()));
                } else if (strcmp(s, "exp") == 0) {
                    push(exp(pop()));
                } else if (strcmp(s, "pow") == 0) {
                    op2 = pop();
                    push(pow(pop(), op2));
                } else {
                    printf("Error: unknown or unsupported command/function %s\n", s);
                }
                break;
            case VARASSIGN:
                //printf("\t\tIn case VASSGN: we got type, s = [%d], [%s]\n", type, s);
                assignvar(s);
                break;
            case VARIABLE:
                //printf("\t\tIn case VAR   : we got type, s = [%d], [%s]\n", type, s);
                if (setvar[s[0]-65] == 1) {
                    push(var[s[0]-65]);
                } else {
                    printf("\tVariable %c has not been set.\n", s[0]);
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
void assignvar(char str[]) {
    int v = str[0] - 65;
    double val;
    char st[MAXOP];
    int i = 2;
    int j = 0;
    while (str[i] != '\0') {
        st[j++] = str[i];
        i++;
    }
    st[j] = '\0';
    val = atof(st);
    var[v] = val;
    setvar[v] = 1;
    printf("\tAssigned %c the value %g\n", str[0], val);
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
    int single_char;
    i = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t') { ; }

    if (c == '-') {
        single_char = c;
        c = getch();
        if (!isdigit(c)) {    // unary minus
            s[++i] = '\0';
            if (c != EOF) {
                ungetch(c);
            }
            return single_char;
        } else {              // negative number
            s[++i] = c;
        }
    } else if (c == '\n') {
        s[++i] = '\0';
        return c;
    } else if (!isdigit(c)) {
        /* all operators other than "-" i.e. *, /, %, +
         * all single character functions i.e. p, d, s, c
         * New in this program: handling variable assignments
         */

        single_char = c;
        s[++i] = c = getch();
        if (c == ' ' || c == '\t' || c == '\n') {
            ungetch(c);
            s[i] = '\0';

            if (single_char >= 65 && single_char <= 90) {
                return VARIABLE;
            } else {
                return single_char;
            }
        } else if (single_char >= 65 && single_char <= 90 && c == '=' ) {
            /* variable assignment */
            while ( isdigit(s[++i] = c = getch()) || c == '.' || c == '-' ) { ; }
            s[i] = '\0';
            return VARASSIGN;
        } else {
            while ( !isdigit(s[++i] = c = getch()) && c != ' ' && c != '\t' && c != '\n' ) { ; }

            if (c != EOF) {
                ungetch(c);
            }
            s[i] = '\0';
            return FUNCTION;
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

