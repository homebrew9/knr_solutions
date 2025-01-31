/*
 * Filename:    detab.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        27-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-20, page 34
 *
 * Write a program detab that replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 *
 * Usage: ./detab < ../ch01/tabs_to_spaces.txt
 * Check: cat -vET ../ch01/tabs_to_spaces.txt
 *        ./detab < ../ch01/tabs_to_spaces.txt | cat -vET
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define TABWIDTH 8

int main(void)
{
    int i;
    int c, col, spaces;

    col = 0;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            /* Important to understand the expression below. The % operator has
             * higher precendence than - operator. So, col % TABWIDTH is evaluated
             * first.
             * For 0 <= col <= 7, it returns col, hence spaces = 8 - col.
             * For col = 8, it returns 0, hence spaces = 8.
             */
            spaces = TABWIDTH - col % TABWIDTH;
            for (i = 0; i < spaces; ++i)
                putchar(' ');
            col = col + spaces;
        } else {
            putchar(c);
            col = col + 1;
            if (c == '\n')
                col = 0;
        }
    }
    return EXIT_SUCCESS;
}

