#include <stdio.h>
#include <stdlib.h>
int main () {
    char * str1 = "bad_input";
    char * str2 = "123bad_input";
    char * last = 0;

    int x1 = 0;
    long x2 = 0;

    x1 = atoi (str1);
    printf ("atoi (x1)          = %d\n", x1);
    x2 = strtol (str1, &last, 10);
    printf ("strtol (x1)        = %ld\n", x2);
    printf ("Original input     = '%s'\n", str1);
    printf ("Parsing stopped at : '%s'\n", last);

    printf("\n");
    x1 = atoi (str2);
    printf ("atoi (x1)          = %d\n", x1);
    x2 = strtol (str2, &last, 10);
    printf ("strtol (x1)        = %ld\n", x2);
    printf ("Original input     = '%s'\n", str2);
    printf ("Parsing stopped at : '%s'\n", last);

    return 0;
}

