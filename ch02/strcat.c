#include <stdio.h>

/* strcat: concatenate to to end of s; s must be big enough
 * I used a different name than "strcat" in order to avoid this
 * error thrown by gcc:
 * =============================================================================
 *     strcat.c:4:6: warning: conflicting types for built-in function ‘strcat’
 *      void strcat(char s[], char t[]) {
 *           ^
 * =============================================================================
 */

void stringcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0') { /* find end of s */
        i++;
    }
    while ((s[i++] = t[j++]) != '\0') { /* copy t */
        ;
    }
}

int main(void) {
    char str1[] = "the quick brown fox";
    char str2[] = "jumps over the lazy dog";

    printf("Before calling stringcat:\n");
    printf("str1 = [%s]\n", str1);
    printf("str2 = [%s]\n", str2);

    stringcat(str1, str2);

    printf("\nAfter calling stringcat:\n");
    printf("str1 = [%s]\n", str1);
    printf("str2 = [%s]\n", str2);
}

