/* Define a macro swap(t, x, y) that interchanges two arguments of type t.
 * (Block structure will help.)
 */
#include <stdio.h>
#define swap(t, x, y) \
            t tmp ## x ## y;      \
            tmp ## x ## y = x;    \
            x = y;    \
            y = tmp ## x ## y;

int main(void) {

    int p = 111;
    int q = 222;
    printf("Before macro call: p = [%d], q = [%d]\n", p, q);
    swap(int, p, q);
    printf("After macro call : p = [%d], q = [%d]\n", p, q);

    printf("\n");
    int a = 1112;
    int b = 22;
    printf("Before macro call: a = [%d], b = [%d]\n", a, b);
    swap(int, a, b);
    printf("After macro call : a = [%d], b = [%d]\n", a, b);

    printf("\n");
    double r = -123.4588901;
    double s = 1.67E34;
    printf("Before macro call: r = [%g], s = [%g]\n", r, s);
    swap(double, r, s);
    printf("After macro call : r = [%g], s = [%g]\n", r, s);

    return 0;
}

