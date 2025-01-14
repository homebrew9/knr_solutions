/* Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minumum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough.
 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void reverse(char s[]) {
    /* reverse: reverse string s in place */
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int w) {
    /* itoa: convert n to characters in s */
    int i, sign;

    if ((sign = n) < 0) { /* record sign */
        n = -n;           /* make n positive */
    }
    i = 0;
    do {    /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0) {
        s[i++] = '-';
    }
    int diff;
    for (diff = w - strlen(s); diff > 0; diff--) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    int num = -789381;
    char str[MAXLINE];
    int width = 10;

    printf("Before calling itoa:\n");
    printf("num   = [%d]\n", num);
    printf("str   = [%s]\n", str);
    printf("width = [%d]\n", width);

    itoa(num, str, width);

    printf("\nAfter calling itoa :\n");
    printf("num   = [%d]\n", num);
    printf("str   = [%s]\n", str);
    return 0;
}

