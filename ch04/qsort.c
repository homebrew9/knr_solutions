/* This is the recursive Quicksort program from Section 4.10 in KnR */
#include <stdio.h>
#define MAXELEM 5

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;
    //void swap(int v[], int i, int j);

    if (left >= right) {  /* do nothing if array contains */
        return;           /* fewer than two elements */
    }
    swap(v, left, (left+right)/2);  /* move partition element */
    last = left;                    /* to v[0] */
    for (i = left+1; i<=right; i++) {  /* partition */
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);  /* restore partition element */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    printf("    Swap v[%d]=%d and v[%d]=%d\t:", i, v[i], j, v[j]);
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    for (i = 0; i < MAXELEM; i++) {
        printf("\t%d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int num[MAXELEM] = { 8, 2, 3, 0, 5 };
    int i;
    //printf("Before qsort, array =\n\t");
    printf("    Before qsort, array  =\t:");
    for (i = 0; i < MAXELEM; i++) {
        printf("\t%d", num[i]);
    }
    printf("\n\n");
    qsort(num, 0, MAXELEM-1);
    //printf("After qsort, array =\n\t");
    printf("\n");
    printf("    After  qsort, array  =\t:");
    for (i = 0; i < MAXELEM; i++) {
        printf("\t%d", num[i]);
    }
    printf("\n");
    return 0;
}

