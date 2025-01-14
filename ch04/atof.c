/* atof: convert string s to double. Section 4.2 in KnR */
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i=0; isspace(s[i]); i++) {  /* skip white space */
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

int get_line(char s[], int max) {
    int c, n;
    n = 0;
    while ((c = getchar()) != '\n' && n < max) {
        s[n++] = c;
    }
}

/* rudimentary calculator */
int main(void) {
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);

    sum = 0;
    while (get_line(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
}

