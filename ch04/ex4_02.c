/* Extend atof to handle scientific notation of the form 123.45e-6 where a
 * floating-point number may be followed by e or E and an optionally signed
 * exponent.
 */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int get_line(char s[], int max) {
    int c, i;
    i = 0;
    while ((c = getchar()) != '\n' && i < max) {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

double atof(char s[]) {
    int sign, i, expsign, exppower;
    double val, power, exponent;
    /* Disregard whitespace at the beginning */
    for (i=0; isspace(s[i]); i++) {
        ;
    }
    sign = 1;
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
        power *= 10.0;
    }

    /* If expsign is 1.0, we multiply with exponent. If expsign
     * is -1.0, we divide by exponent.
     */
    expsign = 1.0;
    exponent = 1.0;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (s[i] == '-') {
            expsign = -1.0;
            i++;
        }
        for (exppower = 0; isdigit(s[i]); i++) {
            exppower = 10 * exppower + (s[i] - '0');
        }
        while (exppower > 0) {
            exponent *= 10.0;
            exppower--;
        }
    }
    if (expsign == 1.0) {
        return sign * val / power * exponent;
    } else if (expsign == -1.0) {
        return sign * val / power / exponent;
    }
}

int main(void) {
    char line[MAXLINE];
    int num;

    printf("Enter a floating point number per line, press Return to quit:\n");
    num = get_line(line, MAXLINE);

    while (num > 0) {
        printf("\tInput string     = [%s]\n", line);
        printf("\tConverted double = [%.20f]\n", atof(line));
        num = get_line(line, MAXLINE);
    }
}

