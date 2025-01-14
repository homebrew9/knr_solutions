#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100

void reverse1(char *s);
void reverse2(char *s);
int strlen(char *s);

int main(void) {
    char str[MAXLEN] = "The woods are lovely dark and deep, but I have promises to keep, and miles to go before I sleep";
    printf("Original string: str = |%s|\n", str);
    reverse1(str);
    printf("After  reverse1: str = |%s|\n", str);
    reverse2(str);
    printf("After  reverse2: str = |%s|\n", str);
    printf("Length of string     = %d\n", strlen(str));
    return 0;
}

int strlen(char *s) {
    int len;
    len = 0;
    while (*(s+len) != '\0') {
        len++;
    }
    return len;
}

void reverse1(char *s) {
    int len = strlen(s);
    int temp;
    int left;
    int right;

    left = 0;
    right = len - 1;
    while (left < right) {
        temp = *(s+left);
        *(s+left) = *(s+right);
        *(s+right) = temp;
        left++;
        right--;
    }
}

void reverse2(char *s) {
    int len = strlen(s);
    int temp;
    int left;
    int right;

    /* And here's the same logic using a "for" loop */
    for (left = 0, right = len-1; left < right; left++, right--) {
        temp = *(s+left);
        *(s+left) = *(s+right);
        *(s+right) = temp;
    }
}

