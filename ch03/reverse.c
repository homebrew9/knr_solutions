#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    /* reverse: reverse string s in place */
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(void) {
    //char s1[] = "the quick brown fox jumps over the lazy dog";
    char s1[] = "a man a plan a canal panama";
    //char s1[] = "ultramicroscopicpneumonovolcanoconiosis";
    printf("Before calling reverse(s1)\n");
    printf("s1 = %s\n", s1);
    reverse(s1);
    printf("\nAfter calling reverse(s1)\n");
    printf("s1 = %s\n", s1);
    return 0;
}

