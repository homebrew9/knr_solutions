/* Write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 * =============================================================================
 * Important: Don't know why the string s3 is garbled!! Use pointers perhaps?
 * =============================================================================
 */
#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
}

void unescape(char str1[], char str2[]) {
    int i, j;
    i = j = 0;
    while (str2[i] != '\0') {
        switch (str2[i]) {
            case '\\':
                i++;
                if (str2[i] == 'n') {
                    str1[j] = '\n';
                    break;
                } else if (str2[i] == 't') {
                    str1[j] = '\t';
                    break;
                } else {
                    str1[j++] = '\\';
                }
            default:
                str1[j] = str2[i];
                break;
        }
        i++;
        j++;
    }
}

int main(void) {
    char s1[] = "";
    char s2[] = "the quick\tbrown\tfox jumps\nover the\n\tlazy dog";
    printf("Before calling escape(s1,s2)\n");
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    escape(s1, s2);
    printf("\nAfter calling escape(s1, s2)\n");
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    char s3[] = "";
    char s4[] = "the woods\\tare\\tlovely,\\ndark\\t\\tand\\ \\deep";
    printf("\n==============================================================\n");
    printf("Before calling unescape(s3,s4)\n");
    printf("s3 = %s\n", s3);
    printf("s4 = %s\n", s4);
    unescape(s3, s4);
    printf("\nAfter calling unescape(s3, s4)\n");
    printf("s3 = %s\n", s3);
    printf("s4 = %s\n", s4);

    return 0;
}

