/* The echo program version 2 in Section 5.10 of KnR */
#include <stdio.h>

/* echo command-line arguments; 2nd version */
int main(int argc, char *argv[]) {
    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}

