#include <stdio.h>
#define MAXLEN 13 
#define COUNT 6 

int main(void) {
    printf("Program to test number arrays.\n\n");
    int n[MAXLEN];
    int i;
    for (i = 0; i < COUNT; i++) {
        n[i] = i;
    }
    printf("MAXLEN = [%d]\n", MAXLEN);
    printf("COUNT = [%d]\n", COUNT);
    printf("================================\n");
    int j;
    for (j = 0; j <= MAXLEN; j++) {
        printf("n[%2d]  = [%d]\n", j, n[j]);
    }
    printf("================================\n");
    for (j = -1; j >= (-1)*MAXLEN; j--) {
        printf("n[%3d]  = [%d]\n", j, n[j]);
    }
}

