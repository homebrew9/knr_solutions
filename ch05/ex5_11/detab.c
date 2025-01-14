/* Modify the programs entab and detab (written as exercises in Chapter 1)
 * to accept a list of tab stops as arguments. Use the default tab settings if
 * there are no arguments.
 *
 * Usage:
 *     ./detab 8 6 6 4 4 < sample.txt
 *
 */
#include <stdio.h>
#define MAXLEN 100
#define FILLER '#'

int main(int argc, char *argv[]) {
    int tabs[MAXLEN], temp = 0, len = 0;

    while (--argc) {
        tabs[len] = temp + atoi(*++argv);
        temp = tabs[len];
        len++;
    }

    int c;
    int col = 1;
    int ind = 0;
    int nexttab = tabs[ind];
    int numtabs, i;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            col = 1;
            ind = 0;
            nexttab = tabs[ind];
            printf("%c", c);
        } else {
            if (col > nexttab && ind < len-1) {
                ind++;
                nexttab = tabs[ind];
            }
            //printf("%2d:%2d:", col, nexttab);
            if (c == '\t') {
                numtabs = nexttab - col + 1;
                for (i = 0; i < numtabs; i++) {
                    printf("%c", FILLER);
                    col++;
                }
                //printf("\n");
            } else {
                //printf("%c\n", c);
                printf("%c", c);
                col++;
            }
        }
    }

    return 0;

}

