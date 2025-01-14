/* Rewrite appropriate programs from earlier chapters and exercises with
 * pointers instead of array indexing. Good possibilities include getline
 * (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */
#include <stdio.h>
#define MAXLEN 100

void print_line(char s, int n);
void reverse(char *s);
int strindex(char *s, char *t);
int get_line(char *s, int limit);
int atoi(char *s);
void itoa(int n, char *s);

int main(void) {
    char str[MAXLEN] = "the quick brown fox jumps over the lazy dog";
    printf("Before reverse: str = [%s]\n", str);
    reverse(str);
    printf("After reverse : str = [%s]\n", str);
    reverse(str);
    printf("After reverse : str = [%s]\n", str);

    print_line('-', 80);
    char sub[MAXLEN] = "over";
    printf("Before strindex:\n");
    printf("    str = [%s]\n", str);
    printf("    sub = [%s]\n", sub);
    printf("Return value of strindex(str, sub) = %d\n", strindex(str, sub));
    printf("Return value of strindex(str, \"%s\") = %d\n", "dog", strindex(str, "dog"));
/*
    print_line('-', 80);
    printf("Testing get_line function.\nEnter a line below (max length %d):\n", MAXLEN);
    char input[MAXLEN];
    int retval;
    retval = get_line(input, MAXLEN);
    printf("\nReturn value of get_line = %d\n", retval);
    printf("The line entered is as follows:\n");
    printf("%s\n", input);
*/
    print_line('-', 80);
    char s1[MAXLEN] = "-67880921";
    printf("Before atoi:      s1 = [%s]\n", s1);
    printf("Return value of atoi = [%d]\n", atoi(s1));

    print_line('-', 80);
    int num = -1234567890;
    char s2[MAXLEN];
    printf("Before itoa:\n");
    printf("    num = [%d]\n", num);
    printf("    s2  = [%s]\n", s2);
    itoa(num, s2);
    printf("After itoa :\n");
    printf("    num = [%d]\n", num);
    printf("    s2  = [%s]\n", s2);

    return 0;
}

void itoa(int n, char *s) {
    static int i = 0;
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    int rem, quot;
    quot = n / 10;
    rem = n % 10;
    if (quot == 0) {
        s[i++] = rem + '0';
    } else {
        itoa(quot, s);
        s[i++] = rem + '0';
        s[i] = '\0';
    }
}


int atoi(char *s) {
    int sign = 1;
    int i = 0;
    int n = 0;
    if (*(s + i) == '-') {
        sign = -1;
        i++;
    } else if (*(s + i) == '+') {
        sign = 1;
        i++;
    }
    while (*(s + i) != '\0') {
        n = n*10 + *(s + i) - '0';
        i++;
    }
    return sign*n;
}

int get_line(char *s, int lim) {
    int c, i;
    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void print_line(char s, int n) {
    int i = 0;
    printf("\n");
    while (i++ < n) {
        printf("%c", s);
    }
    printf("\n");
}

void reverse(char *s) {
    int right = 0;
    while (*(s+right) != '\0') { right++; }
    int left, temp;
    for (left = 0, right--; left < right; left++, right--) {
        temp = *(s+left);
        *(s+left) = *(s+right);
        *(s+right) = temp;
    }
}

int strindex(char *s, char *t) {
    int i, j, k;
    for(i = 0; *(s+i) != '\0'; i++) {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) { ; }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

