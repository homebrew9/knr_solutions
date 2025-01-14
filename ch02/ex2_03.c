/* Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f, and A through F.
 */
#include <stdio.h>

int main() {
    test_htoi();
    return 0;
}

int test_htoi() {
    // We will test htoi function a few times with different inputs
    // 1) 123
    char str[] = "123";
    printf("Hex input  = %s\n", str);
    int num = htoi(str);
    if (num != -1) { printf("Dec output = %d\n", num); }
    // 2) 12AF
    char str1[] = "12AF";
    printf("\nHex input  = %s\n", str1);
    num = htoi(str1);
    if (num != -1) { printf("Dec output = %d\n", num); }
    // 3) 0X12af
    char str2[] = "0x12AF";
    printf("\nHex input  = %s\n", str2);
    num = htoi(str2);
    if (num != -1) { printf("Dec output = %d\n", num); }
}

int htoi(char s[]) {
    int i = 0;
    int start = 0;
    int n = 0;
    if (s[i] == '0') {
        i++;
        if (s[i] != 'x' && s[i] != 'X') {
            printf("Invalid hexadecimal number: %s\n", s);
            return -1;
        } else {
            i++;
        }
    }
    while (s[i] != '\0') {
        if ( !(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'A' && s[i] <= 'F') && !(s[i] >= 'a' && s[i] <= 'f')) {
             printf("Invalid hexadecimal number: %s\n", s);
             return -1;
        } else if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
        } else {
            n = 16 * n + (s[i] - 'a' + 10);
        }
        i++;
    }
    return n;
}

