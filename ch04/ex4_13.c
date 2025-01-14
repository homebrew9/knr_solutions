/* Write a recursive version of the function reverse(s), which reverses
 * the string s in place.
 */

#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void reverse(char s[]);

int main(void) {
    char str[MAXLEN] = "abcdefghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("len = %d, str = |%s|\n", strlen(str), str);
    reverse(str);
    printf("len = %d, str = |%s|\n", strlen(str), str);
}

/*
void reverse(char s[]) {
    int left = 0;
    int right = strlen(s) - 1;
    int c;
    while (left < right) {
        c = s[left];
        s[left] = s[right];
        s[right] = c;
        left++;
        right--;
    }
}
*/

/*
void reverse(char s[]) {
    printf("\tI received %s\n", s);
    char st[MAXLEN];
    int i;
    int j;
    j = 0;
    static char st1[MAXLEN];
    static int len;
    if (strlen(s) > 0) {
        for(i = 1; i <= strlen(s)-1; i++) {
            st[j++] = s[i];
        }
        st[j] = '\0';

        reverse(st);

        st1[len++] = s[0];
        st1[len] = '\0';
    } else {
        st1[0] = '\0';
        len = 0;
    }
    printf("\tLet me print %c from %s : and st1 = %s\n", s[0], s, st1);
//    if (strlen(s) == strlen(st1)) {
//        printf("We are in if...\n");
//        s = st1;
//    }
}
*/

void reverse(char s[]) {
    int c;
    int swapwith;
    static int marker = -1;
    marker++;
    //printf("\tmarker = %d\n", marker);
    swapwith = strlen(s) - marker - 1;
    if (marker < strlen(s)/2) {
        //printf("\t\tSwap %d and %d\n", marker, swapwith);
        c = s[marker];
        s[marker] = s[swapwith];
        s[swapwith] = c;
        reverse(s);
    }
}

