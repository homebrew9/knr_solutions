/* Write a pointer version of strcat function strcat that we showed in
 * Chapter 2: strcat(s, t) copies string t to the end of s.
 */
#include <stdio.h>
#define MAXLEN 1000

/* I use a function name other than strcat because gcc throws the warning
 * shown below. Apparently, the signature conflicts with that of the standard
 * strcat function:
 *
 *     warning: conflicting types for built-in function ‘strcat’
 *     void strcat(char *s, char *t);
 *          ^
 *
 */
void strconcat(char *s, char *t);

int main(void) {
    char s1[MAXLEN] = "Hope is a good thing, maybe the best of things, ";
    char s2[MAXLEN] = "and no good thing ever dies.";
    printf("Before strconcat:\n");
    printf("\ts1 = [%s]\n", s1);
    printf("\ts2 = [%s]\n", s2);
    strconcat(s1, s2);
    printf("===================================================================\n");
    printf("After strconcat :\n");
    printf("\ts1 = [%s]\n", s1);
    printf("\ts2 = [%s]\n", s2);
    return 0;
}

void strconcat(char *s, char *t) {
    int i, j;
    for (i = 0; *(s+i) != '\0'; i++) { ; }
    for (j = 0; *(t+j) != '\0'; j++) {
        *(s+i+j) = *(t+j);
    }
    *(s+i+j) = '\0';
}

