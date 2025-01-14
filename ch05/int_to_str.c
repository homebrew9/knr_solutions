/* A quick and dirty function to convert an int to str.
 *     int_to_str  => converts int n to string s using array subscripts
 *     int_to_str1 => does the same conversion using pointers, but the string is in reverse
 *     reverse     => reverses a string in place using pointers
 *     itos        => uses int_to_str1 and reverse to convert an int to string
 */
#include <stdio.h>
#define MAXLEN 100

void int_to_str(int n, char s[]);
void int_to_str1(int n, char *s);
void reverse(char *s);
void itos(int n, char *s);

int main(void) {
    char str[MAXLEN];
    int num = -2390478;
    printf("num = [%d]\n", num);

    itos(num, str);
    printf("str = [%s]\n", str);

    //int_to_str(num, str);
    //printf("str = [%s]\n", str);
}

void int_to_str(int n, char s[]) {
    static int i = 0;
    if (n/10 != 0) {
        int_to_str(n/10, s);
    }
    s[i++] = (n%10) + '0';
    s[i] = '\0';
}

void itos(int n, char *s) {
    if (n < 0) {
        *s++ = '-';
        n = -n;
    }
    int_to_str1(n, s);
    reverse(s);
}

void int_to_str1(int n, char *s) {
    while (n/10 != 0) {
        *s++ = n%10 + '0';
        n /= 10;
    }
    *s++ = n%10 + '0';
    *s = '\0';
}

void reverse(char *s) {
    char *lptr = s;
    int left = 0, right = 0, temp;
    char *rptr = s;
    while (*rptr) {
        *rptr++;
        right++;
    }
    *rptr--;
    right--;
    for ( ; left < right; *lptr++, left++, *rptr--, right--) {
        temp = *lptr;
        *lptr = *rptr;
        *rptr = temp;
    }
}

