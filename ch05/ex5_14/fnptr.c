/* A test program to become familiar with the concept of pointers to functions.
 * Also consult Chapter 17 of KNK book on this.
 */
#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void iterate(int x, void (*f)(int n, char *s));  /* (*f) means pointer to function f */
void get_text(int n, char *s);

int main(int argc, char *argv[]) {
    int last = 10;
    iterate(last, (*get_text));  /* "iterate(last, get_text)" is legal as well. */
}

void iterate(int x, void (*f)(int n, char *s)) {
    int i;
    char str[MAXLEN];
    for (i = 1; i <= x; i++) {
        (*f)(i, str);
        printf("%3d : %s\n", i, str);
    }
}

void get_text(int n, char *s) {
    if (n % 2 == 0) {
        strcpy(s, "Even number.");
    } else {
        strcpy(s, "Odd  number.");
    }
}

