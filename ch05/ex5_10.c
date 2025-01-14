/* Write the program expr, which evaluates a reverse Polish expression from the
 * command line, where each operator or operand is a separate argument. For
 * example,
 *
 *     expr 2 3 4 + *
 *
 * evaluates 2 x (3 + 4).
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
void push(char s[]);
char *pop();
void ftoa(float n, char *s);

void itos(int n, char *s);
void int_to_str1(int n, char *s);
void reverse(char *s);

void frac_to_str(char *s, float n, int d);

static char *stack[MAXLEN];
static int maxindex = 0;

int main(int argc, char *argv[]) {
    char str[MAXLEN];
    char *ptr[MAXLEN];
    char *p1[MAXLEN];
    char *p2[MAXLEN];
    int c;
    float result;
    while (--argc > 0) {
        *ptr = *++argv;
        c = *ptr[0];
        switch (c) {
            case '+':
                /* An operand may start with "+" - unlikely, but possible.
                 * If the length is 1, we know for sure it is an operator.
                 */

                /* process if operator; else push */
                if (strlen(*ptr) == 1) {
                    *p1 = pop();
                    *p2 = pop();
                    result = atof(*p1) + atof(*p2);
                    ftoa(result, str);
                    push(str);
                } else {
                    push(*ptr);
                }
                break;
            case '-':
                /* An operand may start with "-"; if the length is 1, we know
                 * for sure that it is an operator.
                 */

                /* process if operator; else push */
                if (strlen(*ptr) == 1) {
                    *p1 = pop();
                    *p2 = pop();
                    result = atof(*p2) - atof(*p1);
                    ftoa(result, str);
                    push(str);
                } else {
                    push(*ptr);
                }

                break;
            case '*':
                /* process the operation; no ambiguity here */
                *p1 = pop();
                *p2 = pop();
                result = atof(*p2) * atof(*p1);
                ftoa(result, str);
                push(str);

                break;
            case '/':
                /* process the operation; no ambiguity here */
                *p1 = pop();
                *p2 = pop();
                result = atof(*p2) / atof(*p1);
                ftoa(result, str);
                push(str);
                break;
            default:
                push(*ptr);
                break;
        }
    }
    /* We may have more than one elements in the stack at this point, if there were
     * more operands than there were operators. In any case, the element with the
     * highest index is the answer.
     */
    printf("Answer = %s\n", stack[maxindex-1]);
}

void push(char s[]) {
    stack[maxindex] = s;
    maxindex++;
}

char *pop() {
    maxindex--;
    return stack[maxindex];
}

void ftoa(float n, char *s) {
    /* determine the integer and fractional parts */
    int it = (int)n;
    float ft = n - it;
    if (ft < 0) {
        ft = -ft;
    }

    /* convert the integer part to a string first */
    itos(it, s);

    /* append the decimal point and then 6 digits of fractional part */
    char *ptr = s;
    while (*ptr) { *ptr++; }
    *ptr++ = '.';
    *ptr = '\0';

    int digits = 6;
    frac_to_str(s, ft, digits);
}

void itos(int n, char *s) {
    if (n < 0) {
        *s++ = '-';
        n = -n;
    }
    int_to_str1(n, s);
    reverse(s);
}

void int_to_str1(int n, char *s) {
    while (n/10 != 0) {
        *s++ = n%10 + '0';
        n /= 10;
    }
    *s++ = n%10 + '0';
    *s = '\0';
}

void reverse(char *s) {
    char *lptr = s;
    int left = 0, right = 0, temp;
    char *rptr = s;
    while (*rptr) {
        *rptr++;
        right++;
    }
    *rptr--;
    right--;
    for ( ; left < right; *lptr++, left++, *rptr--, right--) {
        temp = *lptr;
        *lptr = *rptr;
        *rptr = temp;
    }
}

void frac_to_str(char *s, float n, int d) {
    while (*s) {
        *s++;
    }
    int i = 0;
    while (i++ < d) {
        n *= 10;
        *s++ = (int)n%10 + '0';
    }
    *s = '\0';
}

