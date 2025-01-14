#include <stdio.h>
#include <string.h>
#define MAXLEN 10 

int main(void) {
    printf("Program to test strings and how they work as character arrays.\n\n");
    char s[MAXLEN] = "abcd";
    printf("MAXLEN = %d\n", MAXLEN);
    printf("s = [%s]\n", s);
    printf("strlen(s) = [%d]\n", strlen(s));
    printf("================================\n");
    int i;
    for (i = 0; i <= MAXLEN; i++) {
        printf("s[%2d]  = [%c|%d]\n", i, s[i], s[i]);
    }
    printf("================================\n");
    for (i = -1; i >= (-1)*MAXLEN; i--) {
        printf("s[%3d]  = [%c|%d]\n", i, s[i], s[i]);
    }
}

