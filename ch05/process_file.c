/* A short, quick program to process input text stream and determine the
 * frequency counts of lower case and upper case characters (a through z).
 * I have used pointers to int and char arrays here.
 */
#include <stdio.h>
#define MAXLEN 1000
#define SIZE 26

void initialize_arrays(int *lo, int *up);
void print_arrays(int *lo, int *up, char type);
void update_counts(char *s, int *lo, int *up);

int main(void) {
    int lower[SIZE], upper[SIZE];
    initialize_arrays(lower, upper);
    /* Updating the counter per character read will result in way too many
     * function calls. On the other hand, storing the entire text in a single
     * array might require excessive storage. Processing line-by-line or per
     * MAXLEN characters seems to be the happy medium; that's what we do here.
     */
    char str[MAXLEN];
    int j = 0;
    int c;
    while ((c = getchar()) != EOF) {
        str[j++] = c;
        if (c == '\n' || j == MAXLEN - 1) {
            str[j] = '\0';
            update_counts(str, lower, upper);
            j = 0;
        }
    }
    //print_arrays(lower, upper, 'o');
    print_arrays(lower, upper, 's');
}

void initialize_arrays(int *lo, int *up) {
    int i;
    for (i = 0; i < SIZE; i++) {
        lo[i] = 0;
        up[i] = 0;
    }
}

void print_arrays(int *lo, int *up, char type) {
    /* type = 'o' : print arrays one after the other
     * type = 's' : print arrays side by side
     * Note that you can use *(lo + i) instead of lo[i] and so on.
     */
    int i;
    for (i = 0; i < SIZE; i++) {
        if (type == 'o') {
            printf("%c => %6d\n", (i + 'a'), lo[i]);
        } else if (type == 's') {
            printf("%c => %6d  |  %c => %6d\n", (i + 'a'), lo[i], (i + 'A'), up[i]);
        }
    }
    if (type == 'o') {
        printf("-------------------------------\n");
        for (i = 0; i < SIZE; i++) {
            printf("%c => %6d\n", (i + 'A'), up[i]);
        }
    }
}

void update_counts(char *s, int *lo, int *up) {
    int i = 0;
    while (s[i] != '\0') {
        /* Update the counter of the appropriate array */
        if (s[i] >= 'a' && s[i] <= 'z') {
            lo[s[i] - 'a'] += 1;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            up[s[i] - 'A'] += 1;
        }
        i++;
    }
}

