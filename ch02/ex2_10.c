/* Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 */
#include <stdio.h>

void lower(char s[]) {
    int i;
    // If a character is uppercase A-Z, we add 32 to it. 32 = 'a' - 'A'. Thus:
    //     'M' (ascii 77) gets converted to 'm' (ascii 109 = 77+32), and
    //     'Q' (ascii 81) gets converted to 'q' (ascii 113 = 81+32)
    // If the character is something else, we add 0 to its ascii value.
    for (i = 0; s[i] != '\0'; ++i) {
        s[i] += (s[i] >= 'A' && s[i] <= 'Z') ? 'a' - 'A' : 0;
    }
}

int main(void) {
    char str[] = "The Quick Brown FOX: jumPS over The LAZY dOg!";
    printf("Before calling lower: [%s]\n", str);
    lower(str);
    printf("After calling lower : [%s]\n", str);
    return 0;
}

