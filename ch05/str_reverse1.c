/* Yet another string reversal program that I found on the Internet at
 * this location:
 *     http://www.advogato.org/article/1043.html
 *
 * Original program is as follows:
 * -------------------------------------------------------------
 *     #include <stdio.h>
 *     void reverse(const char *s) {
 *         if (s && *s) {
 *             reverse(s+1);
 *             printf("%c",*s);
 *         }
 *     }
 *     
 *     int main(int argc, char **argv) {
 *         if (argc > 1) {
 *             reverse(argv[1]);
 *             printf("\n");
 *         }
 *         return 0;
 *     }
 * -------------------------------------------------------------
 * 
 * I have modified the program a bit.
 */

#include <stdio.h>
#define MAXLEN 100

void reverse(char *s) {
    // doesn't reverse in place, but prints the reversed string
    if (*s) {
        reverse(s+1);
        printf("%c", *s);
    }
}

int main(int argc, char **argv) {
    char str[MAXLEN] = "the quick brown fox jumps over the lazy dog";
    printf("\n");
    printf("%s\n", str);
    reverse(str);
    printf("\n");
    return 0;
}

