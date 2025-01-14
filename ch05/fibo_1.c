/* A quick program to try out an iterative Fibonacci series going
 * from lower to higher index.
 */
#include <stdio.h>

void fibo(int n);

int main(int argc, char *argv[]) {
    int num = 45;
    fibo(num);
    return(0);
}

void fibo(int n) {
    int first = 1;   /* fib(0) = 1 */
    int second = 1;  /* fib(1) = 1 */
    int i, temp;
    if (n <= 1) {
        printf("fibo(%2d) = %15d\n", n, first);
    } else {
        for (i = 2; i <= n; i++) {
            temp = first+second;
            printf("fibo(%2d) = %15d\n", i, temp);
            first = second;
            second = temp;
        }
    }
}

