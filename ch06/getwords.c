#include <stdio.h>
#define MAXLEN 1000

int getword(char *word, int lim);

int main(int argc, char *argv[]) {
    char word[MAXLEN];
    int c;
    while ( (c = getword(word, MAXLEN)) != EOF ) {
        printf("[%c|%s]\n", c, word);
    }
}

int getword(char *word, int lim) {
    char *w = word;
    printf("\tw = [%3d|%c|%p], word = [%s]\n", *w, *w, w, word);
    int c;
    while ( isspace(c = getchar()) ) { ; }
    if (c != EOF) {
        *w++ = c;
    }
    if ( !isalpha(c) ) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        if ( !isalpha(*w = getchar()) ) {
            break;
        }
    }
    *w = '\0';
    return word[0];
}

