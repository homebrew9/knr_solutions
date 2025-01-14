/* The find program from Section 5.10 - "Command line arguments" in KnR.
 * In Section 4.1, the search pattern was wired deep into the program, an
 * obviously unsatisfactory arrangement. Following the lead of the UNIX program
 * grep, let us change the program so the pattern to be matched is specified by
 * the first argument on the command line.
 * This is version 1. It does not take any qualifiers. Version 2 does that.
 * Usage: (1) ./find the < poem.txt
 *        (2) cat poem.txt | ./find the
 *        (4) ./find eagle < bible_kjv.txt
 *        (5) ./find heron < bible_kjv.txt
 *        (6) ./find stork < bible_kjv.txt
 *        (7) ./find wolf < bible_kjv.txt
 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line1(char *line, int max);
int get_line(char line[], int max);

/* find: print lines that match pattern from 1st arg */
int main (int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;
    if (argc != 2) {
        printf("Usage: find pattern\n");
    } else {
        //while (get_line(line, MAXLINE) > 0) {
        while (get_line1(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
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

