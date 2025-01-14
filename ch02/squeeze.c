/* Usage: ./squeeze
 */
#include <stdio.h>

void squeeze(char s[], int c) {
    /* squeeze: delete all c from x */
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char str[] = "the quick brown fox jumps over the lazy dog";
    int chr = 'o'; // also try 'e'
    printf("Chr = %c\n", chr);
    printf("Before squeeze: [%s]\n", str);
    squeeze(str, chr);
    printf("After squeeze : [%s]\n", str);

    chr = 'e';
    char str1[] = "the quick brown fox jumps over the lazy dog";
    printf("\nChr = %c\n", chr);
    printf("Before squeeze: [%s]\n", str1);
    squeeze(str1, chr);
    printf("After squeeze : [%s]\n", str1);

    return 0;
}

