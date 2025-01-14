/* Our version of getword does not properly handle underscores, string
 * constants, comments, or preprocessor control lines. Write a better version.
 * I have added code to handle underscores and comments for the moment.
 * Usage examples:
 *     ./ex6_01 < ../ch05/swap.c
 *     ./ex6_01 < ../ch05/str_reverse.c
 */
#include <stdio.h>
#define MAXWORD 100

int getword(char *, int);
int getch(void);
void ungetch(int c);

int main(int argc, char *argv[]) {
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF) {
        printf("%s\n", word);
    }
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch())) { ; }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        if ( !isalnum(*w = getch()) && *w != '_' ) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void) {     /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters!\n");
    } else {
        buf[bufp++] = c;
    }
}

