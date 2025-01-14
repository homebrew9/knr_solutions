/* Write a function expand(s1, s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases like
 * a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally.
 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void expand(char s1[], char s2[]) {
    int i, j = 0;
    printf("=========================\n");
    while (i < strlen(s1)) {
        if (     i > 0
              && i < strlen(s1) - 1
              && s1[i] == '-'
              && s1[i-1] != ' '
              && s1[i+1] != ' '
              && s1[i-1] < s1[i+1]
           ) {
            int k;
            for(k = s1[i-1]+1; k <= s1[i+1]; k++) {
                s2[j] = k;
                j++;
            }
            i++;
            i++;
        } else {
            s2[j] = s1[i];
            i++;
            j++;
        }
    }
}

int main(void) {
    char str1[MAXLINE] = "-ok A-D and e-a and -a-z and 0-9 and a-z0-9 and i-b-m here-";
    char str2[MAXLINE];
    printf("Before calling expand:\n");
    printf("str1 = [%s]\n", str1);
    printf("str2 = [%s]\n", str2);

    expand(str1, str2);

    printf("\nAfter calling expand:\n");
    printf("str1 = [%s]\n", str1);
    printf("str2 = [%s]\n", str2);

    return 0;
}

