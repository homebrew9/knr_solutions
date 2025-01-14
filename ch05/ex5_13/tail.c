/* Write the program tail, which prints the last n lines of its input. By
 * default, n is 10, let us say, but it can be changed by an optional argument,
 * so that
 *
 *     tail -n
 *
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size.
 *
 * Usage:
 *     ./tail -8 < sample_for_tail.txt
 *     ./tail < sample_for_tail.txt
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 100
#define MAXLINES 10000000  /* Bible KJV has 99,814 lines; I've set MAXLINES to 10,000,000 */
#define TAILLENGTH 10

char *lineptr[MAXLINES]; /* an array, each element of which is a pointer to a text line */
int read_lines(char *lineptr[], int maxlines, int batchsize, int *start_ind);
int get_line(char *s, int lim);
char *alloc(int);

int main(int argc, char *argv[]) {
    int batchsize = TAILLENGTH;
    char *last = 0;

    if (argc > 2) {
        printf("Incorrect number of arguments.\n");
        printf("Usage: ./tail [-n] < file\n");
        return 0;
    } else if (argc > 1) {
        /* atoi function was not good at error checking; so I used strtol. Basically,
         * I want to capture the error if the user passes "-8x" or "-x" as the argument
         * after "tail".
         */
        if (*argv[1] != '-') {
            printf("Qualifier must begin with '-' character.\n");
            printf("Usage: ./tail [-n] < file\n");
            return 0;
        }
        batchsize = strtol(*++argv, &last, 10);
        //printf("*last = [%d|%c]\n", *last, *last);
        //printf("batchsize = [%d]\n", batchsize); 
        if (*last != '\0') {
            printf("Invalid integer passed as argument.\n");
            printf("Usage: ./tail [-n] < file\n");
            return 0;
        }
        if (batchsize == 0) {
            return 0;
        }
        batchsize = -batchsize;
    }
    //printf("argc = [%d]\n", argc);
    //printf("batchsize = [%d]\n", batchsize);

    //while (--argc > 0) {
    //    printf("\t[%d|%s]\n", argc, *++argv);
    //}

    int linecount;
    int start = 0;
    //batchsize = 6;

    linecount = read_lines(lineptr, MAXLINES, batchsize, &start);

    //printf("linecount = [%d], start = [%d]\n", linecount, start);
    int i;
    //for (i = 0; i < linecount; i++) {
    //    printf("[%s]\n", lineptr[i]);
    //}
    //printf("-------------------------------------------------\n");

    int end = linecount < batchsize ? linecount : batchsize;
    for (i = 0; i < end; i++) {
         //printf("[%d|%s]\n", (start + i)%batchsize, lineptr[(start+i)%batchsize]);
         printf("%s\n", lineptr[(start+i)%batchsize]);
    }

    return 0;
}

int read_lines(char *lineptr[], int maxlines, int batchsize, int *start_ind) {
    int len, nlines;
    char *p, line[MAXLEN];
    //int batchsize = 6;
    int now_populate_ind;

    nlines = 0;
    while ( (len = get_line(line, MAXLEN)) > 0 ) {
        now_populate_ind = nlines % batchsize;
        *start_ind = nlines < batchsize ? 0 : ((nlines + 1) % batchsize);
        //printf("\tmaxlines = [%d], nlines = [%2d], batchsize = [%d], now_populate_ind = [%d], start_ind = [%d]\n", maxlines, nlines, batchsize, now_populate_ind, *start_ind);
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            //printf("\tif  : len = [%d], p = [%p]\n", len, *p);
            return -1;
        } else {
            //printf("\telse: len = [%d], p = [%p]\n===========\n", len, *p);
            line[len-1] = '\0';
            strcpy(p, line);
            //lineptr[nlines] = p;
            lineptr[now_populate_ind] = p;
            nlines++;
        }
    }
    return nlines;
}

int get_line(char s[], int lim) {
    int c, i;
    int n = 0;
    for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000000                       /* SIZE OF AVAILABLE SPACE; Bible KJV requires 4,332,555 bytes; I set ALLOCSIZE to 10,000,000 */
static char allocbuf[ALLOCSIZE];                 /* storage for alloc */
static char *allocp = allocbuf;                  /* next free position */
char *alloc(int n) {                             /* return pointer to n characters */
    if (allocbuf + ALLOCSIZE - allocp >= n) {    /* it fits */
        allocp += n;
        return allocp - n;                       /* old p */
    } else {                                     /* not enough room */
        return 0;
    }
}

