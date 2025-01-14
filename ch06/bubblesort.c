/* Trying my hand at Bubble sort. */
#include <stdio.h>
#define MAXLEN 7

void printnums(int n[]);
void sort(int n[]);

int main(int argc, char *argv[]) {
    int nums[MAXLEN];
    nums[0] = 93;
    nums[1] = 57;
    nums[2] = 55;
    nums[3] = 37;
    nums[4] = 23;
    nums[5] = 8;
    nums[6] = 4;
    printnums(nums);
    sort(nums);
}

void printnums(int n[]) {
    int i;
    printf("=====================\n");
    for (i = 0; i < MAXLEN; i++) {
        printf("nums[%d] = %4d\n", i, n[i]);
    }
    printf("=====================\n");
}

void sort(int n[]) {
    int i, temp;
    int len = MAXLEN;

    while (len > 1) {
        printf("len = [%d]\n", len);
        for (i = 1; i < len; i++) {
            // start from the second element and swap elements if the
            // previous element > current. That way:
            // In pass 1, the largest element bubbles to the end
            // In pass 2, the 2nd largest element bubbles to the end-1 slot
            // In pass 3, the 3rd largest element bubbles to the end-2 slot
            // ...
            // In pass n, the nth largest element bubbles to the end-n+1 slot
            // If the array has N elements, we pass through it N-1 times.
            if (n[i-1] > n[i]) {
                temp = n[i-1];
                n[i-1] = n[i];
                n[i] = temp;
            }
        }
        printnums(n);
        len--;
    }
}

