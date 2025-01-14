/* The find program from Section 5.10 - "Command line arguments" in KnR.
 * This is Version 2. It allows optional arguments:
 *     -n => to print line number
 *     -x => to search for lines that do not match the pattern
 * The arguments can be in any order and can be combined.
 * Usage: (1) ./find1 -nx the < ../ch01/voltaire.txt
 *        (2) ./find1 -n -x e > poem.txt
 *        (4) cat poem.txt | ./find -nx e
 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line1(char *line, int max);
int get_line(char line[], int max);

/* find: print lines that match pattern from 1st arg */
int main (int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find1: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        while (get_line1(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) {
                    printf("%ld:", lineno);
                }
                printf("%s", line);
                found++;
            }
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

/* get_line1: get line into line, return length */
int get_line1(char *line, int max) {
    int c, i;
    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n') {
        *line++ = c;
        i++;
    }
    if (c == '\n') {
        *line++ = c;
        i++;
    }
    *line = '\0';
    return i;
}

