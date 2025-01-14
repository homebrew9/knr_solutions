/* Modify the programs entab and detab (written as exercises in Chapter 1)
 * to accept a list of tab stops as arguments. Use the default tab settings if
 * there are no arguments.
 *
 * Usage:
 *     ./entab 8 8 8 8 < sample_1.txt
 *
 */
#include <stdio.h>
#define MAXLEN 100
#define SPACE ' '
#define TAB '\t'

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
    int blanks = 0;
    int nearestind;
    int firstblank = 1;
    int numblanks = 0;
    int delta = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            col = 1;
            ind = 0;
            blanks = 0;
            delta = 0;
            nearestind = 0;
            numblanks = 0;
            printf("%c", c);
        } else {
            if (col > tabs[ind] && ind < len-1) {
                ind++;
            }
            if (c == ' ') {
                blanks++;
                if (firstblank) {
                    nearestind = ind;
                    firstblank = 0;
                }
            } else {
                if (blanks == 0) {
                    printf("%c", c);
                    col++;
                } else {
                    /* Now iterate through the blank space count we have
                     * accumulated till now and convert them to a combination
                     * of TABs and blanks as we keep matching the tabs array.
                     */
                    while (blanks > 0) {
                        numblanks++;
                        delta++;
                        if (col + numblanks - 1 == tabs[nearestind]) {
                            printf("%c", TAB);
                            nearestind++;
                            delta = 0;
                        }
                        blanks--;
                    }
                    while (delta > 0) {
                        printf("%c", SPACE);
                        delta--;
                    }
                    printf("%c", c);
                    col++;
                }
            }
        }
    }
    return 0;
}

