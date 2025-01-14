/* Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats n as a hexadecimal integer in s.
 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void reverse(char s[]) {
    int i, j, c;
    for (i=0, j=strlen(s)-1; i<j; i++,j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    if (b < 2 || b > 16) {
        printf("Base must be in the range [2,16]. Abnormal exit.\n");
        return;
    }
    int i;
    int sign = 1;

    if (n < 0) {
        sign = -1;
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % b + '0' + ((n % b) > 9 ? 7 : 0);
    } while ((n /= b) > 0);
    if (sign == -1) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    int num = 19895;
    char str[MAXLINE];
    int base = 16;
    printf("Before calling itob:\n");
    printf("num  = [%d]\n", num);
    printf("str  = [%s]\n", str);
    printf("base = [%d]\n", base);

    itob(num, str, base);

    printf("\nAfter calling itob :\n");
    printf("num = [%d]\n", num);
    printf("str = [%s]\n", str);
    return 0;
}

