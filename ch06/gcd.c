/* A short program that uses Euclid's algorithm to find GCD using a
 * recursive function. The algorithm is as follows:
 * If a > b then:
 *     gcd(a, b) = gcd(b, a%b)
 *               = a if b = 0
 * If a = b then:
 *     gcd(a, b) = a
 * Usage:
 *     ./gcd M N
 *     where M and N are two positive integers
 * Examples:
 *     ./gcd 1599675135 387037879
 *     ./gcd 15996751 3870378
 *     ./gcd 270 192
 */
#include <stdio.h>

static int call_count = 0;
int gcd(int a, int b);
int gcd_iter(int a, int b);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./gcd M N\n    where M, N are positive integers\n");
        return(1);
    }
    int m, n, result;
    m = atoi(*++argv);
    n = atoi(*++argv);
    result = gcd(m, n);
    printf("==== Using recursive function\n");
    printf("GCD (%d, %d) = %d\n", m, n, result);
    printf("Depth of recursion = %d\n", call_count);

    result = gcd_iter(m, n);
    printf("\n==== Using iterative function\n");
    printf("GCD (%d, %d) = %d\n", m, n, result);
}

int gcd(int a, int b) {
    call_count++;
    //printf("\tCall No. = [%d], args = (%d, %d)\n", call_count, a, b);
    if (b == 0) {
        return a;
    } else if (a == b) {
        return a;
    } else if (a > b) {
        return gcd(b, a%b);
    } else {                 /* b > a */
        return gcd(a, b%a);
    }
}

int gcd_iter(int a, int b) {
    if (b == 0 || a == b) {
        return a;
    }
    int temp;
    int n1 = a > b ? a : b;  /* larger of the two */
    int n2 = a > b ? b : a;  /* smaller of the two */
    //printf("\tnums = (%d, %d)\n", n1, n2);
    for ( ; n2 > 0; temp = n1%n2, n1 = n2, n2 = temp) {
        //printf("\tnums = (%d, %d)\n", n1, n2);
        ;
    }
    return n1;
}

