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

void itoa(int n, char s[]) {
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
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    int num = -789381;
    char str[MAXLINE];

    printf("Before calling itoa:\n");
    printf("num = [%d]\n", num);
    printf("str = [%s]\n", str);

    itoa(num, str);

    printf("\nAfter calling itoa :\n");
    printf("num = [%d]\n", num);
    printf("str = [%s]\n", str);
    return 0;
}

