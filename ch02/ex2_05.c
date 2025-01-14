/* Write the function any(s1,s2), which returns the first location in the
 * string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location.
 * Usage: ./ex2_05
 */
#include <stdio.h>

int any(char s1[], char s2[]) {
    /* any: return the first location of any character of s2 in s1 */
    int i, j;
    int index = -1;
    int found;
    for (i = 0; s1[i] != '\0'; i++) {
        // We now have the character from array s1 in s1[i]
        // We have to loop through s2 and see if s1[i] exists in s2.
        // If it does, we return the index i and break.
        // If it doesn't, we move on to the next character in s1.
        j = 0;
        found = -1;
        while (s2[j] != '\0') {
            if (s2[j] == s1[i]) {
                index = i;
                found = 0;
                break;
            }
            j++;
        }
        // At this point:
        //     found = 0  if a s1[i] exists in s2
        //     found = -1 if a s1[i] does not exists in s2
        if (found == 0) {
            break;
        }
    }
    // We've iterated through s1 entirely without finding a match
    return index;
}

int main() {
    char str1[] = "the quick brown fox jumps over the lazy dog";
    char str2[] = "opensesame!";
    printf("str2 = [%s]\n", str2);
    printf("str1 = [%s]\n", str1);
    int loc = any(str1, str2);
    printf("loc  = %d\n", loc);

    char st1[] = "the quick brown fox jumps over the lazy dog";
    char st2[] = "zg!";
    printf("\nstr2 = [%s]\n", st2);
    printf("str1 = [%s]\n", st1);
    loc = any(st1, st2);
    printf("loc  = %d\n", loc);

    char ss1[] = "the quick brown fox jumps over the lazy dog";
    char ss2[] = "#%~?:}{!";
    printf("\nstr2 = [%s]\n", ss2);
    printf("str1 = [%s]\n", ss1);
    loc = any(ss1, ss2);
    printf("loc  = %d\n", loc);

    return 0;
}

