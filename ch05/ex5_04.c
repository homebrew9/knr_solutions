/* Write the function strend(s,t), which returns 1 if the string t occurs at
 * the end of the string s, and zero otherwise.
 */
#include <stdio.h>
#define MAXLEN 1000

int strend(char *s, char *t);

int main(void) {
    char s1[MAXLEN] = "and miles to go before I sleep";
    char t1[MAXLEN] = "sleep";
    printf("Before calling strend:\n");
    printf("\ts1 = [%s]\n", s1);
    printf("\tt1 = [%s]\n", t1);
    printf("Return value of strend = %d\n", strend(s1, t1));

    printf("=======================================================================\n");
    char s2[MAXLEN] = "true knowledge exists in knowing that you know nothing";
    char t2[MAXLEN] = "everything";
    printf("Before calling strend:\n");
    printf("\ts2 = [%s]\n", s2);
    printf("\tt2 = [%s]\n", t2);
    printf("Return value of strend = %d\n", strend(s2, t2));
    return 0;
}

int strend(char *s, char *t) {
    int i = 0;
    int j = 0;
    /* trying to **NOT** use strlen here */
    while (*(s+i) != '\0') { i++; }
    while (*(t+j) != '\0') { j++; }
    while ( *(s+i-1) == *(t+j-1) ) {
        i--;
        j--;
    }
    return (j > 0) ? 1 : 0;
}

