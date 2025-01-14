/* Our version of getword does not properly handle underscores, string
 * constants, comments, or preprocessor control lines. Write a better version.
 * Notes:
 * ========
 * I have added code to handle underscores and comments for the moment. This
 * program does not have the struct for keywords and the binsearch function
 * to search and increment the word frequency as well. Those are trivial.
 * Modifying getword to capture the (key)words correctly is the difficult part.
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
    /* In order to disregard single and multi line comments, we declare
     * variables as follows. They are all defaulted to 0 (false).
     */
    int in_mlc = 0;  // multi line comment
    int in_slc = 0;  // single line comment

    int temp;

    for ( ; ; )
    {
        c = getch();
//printf("\tRead: [%d|%c]\n", c, c);
        if ( lim == MAXWORD && isspace(c) && in_mlc == 0 && in_slc == 0 ) {
//printf("\tIn if\n");
            ;
        } else if ( c == '/' && (in_mlc == 0 || in_slc == 0) ) {
//printf("\tIn else-01\n");
            temp = c;
            c = getch();
            if (c == '*') {
                in_mlc = 1;
            } else if (c == '/') {
                in_slc = 1;
            } else {
                lim--;
                *w++ = temp;
                ungetch(c);
                *w = '\0';
                return word[0];
            }
        } else if (in_mlc == 1 && c == '*') {
//printf("\tIn else-02\n");
            c = getch();
            if (c == '/')
                in_mlc = 0;
        } else if (in_slc == 1 && c == '\n') {
//printf("\tIn else-03\n");
            in_slc = 0;
        } else if (in_mlc == 1 || in_slc == 1) {
//printf("\tIn else-04\n");
            continue;
        } else if ( !isalpha(c) && c != '_' ) {
//printf("\tIn else-05\n");
            *w++ = c;
            *w = '\0';
            return c;
        } else {
//printf("\tIn else-06\n");
            *w++ = c;
            if (--lim <= 0) {
                *w = '\0';
                return c;
            }
        }
    }
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

