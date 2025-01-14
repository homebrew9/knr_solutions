/* A short program to test scanf function to read float,
 * double and long float.
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
    float fl;
    double db;
    long double ld;

    printf("\nEnter a float below:\n");
    scanf("%f", &fl);
    printf("You entered float: [%f]\n", fl);

    printf("\nEnter a double below:\n");
    scanf("%lf", &db);
    printf("You entered double: [%lf]\n", db);

    printf("\nEnter a long double below:\n");
    scanf("%Lf", &ld);
    printf("You entered long double: [%Lf]\n", ld);
}

