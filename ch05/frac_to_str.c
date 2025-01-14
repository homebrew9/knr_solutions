/* A program to convert the floating point number to a string and append it to
 * the string argument. This might be used to append a fractional part of a
 * number while parsing a floating point number.
 */
#include <stdio.h>
#define MAXLEN 100

void frac_to_str(char *s, float n, int d);

int main(void) {
    char str[MAXLEN] = "-3456.";
    float num = 0.239047815997;
    //float num = 0.23;
    int digits = 5;

    printf("str    = [%s]\n", str);
    printf("num    = [%f]\n", num);
    printf("digits = [%d]\n", digits);

    frac_to_str(str, num, digits);
    printf("str = [%s]\n", str);
}

void frac_to_str(char *s, float n, int d) {
    while (*s) {
        *s++;
    }
    int i = 0;
    while (i++ < d) {
        n *= 10;
        *s++ = (int)n%10 + '0';
    }
    *s = '\0';
}

