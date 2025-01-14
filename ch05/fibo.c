#include <stdio.h>
#include <time.h>
#define SIZE 46
int fibo(int t);
int fibo1(int t);

int main(void) {
    int retval;
    int i;
    clock_t start, past = 0;

    printf("\n==========    USING NON-OPTIMIZED RECURSIVE FIBO    ==========\n\n");
    for (i = 0; i < SIZE; i++) {
        start = clock();
        retval = fibo(i);
        past = clock() - start;
        printf("fibo(%2d) = %15d | Time taken = %9.6f seconds\n", i, retval, (float)past/CLOCKS_PER_SEC);
    }

    printf("\n==========    USING OPTIMIZED RECURSIVE FIBO        ==========\n\n");
    for (i = 0; i < SIZE; i++) {
        start = clock();
        retval = fibo1(i);
        past = clock() - start;
        printf("fibo(%2d) = %15d | Time taken = %9.6f seconds\n", i, retval, (float)past/CLOCKS_PER_SEC);
    }
}

int fibo(int t) {
    if (t <= 1) {
        return 1;
    } else {
        return (fibo(t-1) + fibo(t-2));
    }
}

int fibo1(int t) {
    static int prev[SIZE];
    static int greatest_index = 0;
    if (t > greatest_index) {
        greatest_index = t;
    }
    int val;
    if (t < greatest_index) {
        return prev[t];
    } else if (t <= 1) {
        val = 1;
        prev[greatest_index] = val;
        return val;
    } else {
        val = fibo1(t-1) + fibo1(t-2);
        prev[greatest_index] = val;
        return val;
    }
}

