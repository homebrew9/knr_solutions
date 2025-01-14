/* Write the function strrindex(s, t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 * Usage: ./ex4_01 < sample.txt
 *        cat sample.txt | ./ex4_01
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "the"; /* pattern to search for */

/* find all lines matching pattern */
int main(void) {
    char line[MAXLINE];
    int found = 0;
    int pos;
    while (get_line(line, MAXLINE) > 0) {
        if ((pos = strrindex(line, pattern)) >= 0) {
            printf("%3d|%s", pos, line);
            found++;
        }
    }
    return found;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* strrindex: return index of rightmost t in s, -1 if none */
int strrindex(char s[], char t[]) {
    int i, j, k;
    for (i = strlen(s)-1; i >= 0; i--) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) { ; }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

