/* Write versions of the library functions strncpy, strncat, and strncmp, which
 * operate on at most the first n characters of their argument strings. For
 * example, srncpy(s,t,n) copies at most n characters of t to s. Full
 * descriptions are in Appendix B.
 */
#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void strncopy(char *s, char *t, int n);
void strnconcat(char *s, char *t, int n);
void print_line(char s, int n);
int strncompare(char *s, char *t, int n);
void test_strncmp(char *s, char *t, int n);

int main(void) {
    char s[MAXLEN] = "the quick brown fox";
    char t[MAXLEN] = "jumps over the lazy dog";
    int len1 = 8;

    printf("Before calling strncopy(s,t,n):\n");
    printf("\ts = [%s]\n", s);
    printf("\tt = [%s]\n", t);
    printf("\tn = [%d]\n", len1);
    //strncpy(s, t, 0);
    strncopy(s, t, len1);
    printf("After calling strncopy(s,t,n) :\n");
    printf("\ts = [%s]\n", s);
    printf("\tt = [%s]\n", t);

    print_line('=', 60);
    int len2 = 11;
    printf("Before calling strnconcat(s,t,n):\n");
    printf("\ts = [%s]\n", s);
    printf("\tt = [%s]\n", t);
    printf("\tn = [%d]\n", len2);
    strnconcat(s, t, len2);
    printf("After calling strnconcat(s,t,n) :\n");
    printf("\ts = [%s]\n", s);
    printf("\tt = [%s]\n", t);

    test_strncmp(s, t, 11);
    test_strncmp(s, t, 9);
    test_strncmp(s, t, 8);
    test_strncmp(s, t, 7);
    test_strncmp("abcdefghij", "abcde", 9);
    test_strncmp("abcde", "abcdefghij", 9);
    test_strncmp("abcdefghij", "abxde", 3);
    test_strncmp("abxdefghij", "abcde", 3);

    return 0;
}

void test_strncmp(char *s, char *t, int n) {
    print_line('=', 60);
    printf("Before calling strncompare(s,t,n):\n");
    printf("\ts = [%s]\n", s);
    printf("\tt = [%s]\n", t);
    printf("\tn = [%d]\n", n);
    printf("Return value of strncompare = [%d]\n", strncompare(s, t, n));
    printf("Return value of strncmp     = [%d]\n", strncmp(s, t, n));
}

void print_line(char s, int n) {
    int i = 0;
    printf("\n");
    while (i++ < n) {
        printf("%c", s);
    }
    printf("\n");
}

void strncopy(char *s, char *t, int n) {
    /* If n is 0, there's nothing to copy. If s is shorter than t, then
     * copying n characters from t may increase the length of s. If n is
     * greater than length of t, we stop copying when we reach the end of t.
     */
    int i = 0;
    int j = 0;
    while (n > 0 && *(t+i) != '\0' && i < n) {
        *(s + j) = *(t + i);
        j++;
        i++;
    }
}

void strnconcat(char *s, char *t, int n) {
    if (n == 0) {
        return;
    }
    int i = 0;
    while (*(s + i) != '\0') { i++; }
    int j = 0;
    while (*(t+j) != '\0' && j < n) {
        *(s + i + j) = *(t + j);
        j++;
    }
}

int strncompare(char *s, char *t, int n) {
    int i = 0;
    while (*(s + i) == *(t + i) && i < n) {
        i++;
    }
    //printf("i = [%d], n = [%d]\n", i, n);
    //printf("schr = %c(%d), tchr = %c(%d)\n", *(s+i), *(s+i), *(t+i), *(t+i));
    return (i == n) ? 0 : *(s+i) - *(t+i);
}

