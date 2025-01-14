#include <stdio.h>
void naive_swap(int, int);
void swap(int *, int *);

int main(void) {
    int a;
    int b;
    a = 123;
    b = -789;

    printf("Before naive swap: a = [%d], b = [%d]\n", a, b);
    naive_swap(a, b);
    printf("After naive swap : a = [%d], b = [%d]\n", a, b);

    printf("\n");
    printf("Before right swap: a = [%d], b = [%d]\n", a, b);
    swap(&a, &b);
    printf("After right swap : a = [%d], b = [%d]\n", a, b);

    return 0;
}

void naive_swap(int p, int q) {
    int temp;
    temp = p;
    p = q;
    q = temp;
}

void swap(int *ip, int *iq) {
    int temp;
    temp = *ip;
    *ip = *iq;
    *iq = temp;
}

