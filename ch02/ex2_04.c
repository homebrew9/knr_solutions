/* Write an alternate version of squueze(s1, s2) that deletes
 * each character in s1 that matches any character in the string s2.
 * Usage: ./ex2_04
 */
#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    /* squeeze: delete all characters of s2 from s1 */
    int i, j;
    int k, found;
    for (i = j = 0; s1[i] != '\0'; i++) {
        // We now have the character from array s1 in s1[i]
        // We have to loop through s2 and see if s1[i] exists in s2. If it
        // does not, we assign s1[i] to s1[j] and increment j. If it does,
        // then we do not assign and just go to the next character of s1.
        // The only way we can know if s1[i] exists in s2 is by looping
        // through the **entire** array s2. We short-circuit by breaking out
        // as soon as we find a match, but otherwise we'll have to loop through
        // s2 entirely.
        k = 0;
        found = -1;
        while (s2[k] != '\0') {
            if (s2[k] == s1[i]) {
                found = 0;
                break;
            }
            k++;
        }
        // At this point:
        //     found = 0  if a s1[i] exists in s2
        //     found = -1 if a s1[i] does not exists in s2
        if (found == -1) {
            s1[j++] = s1[i]; // assign to s1[j] and then increment j
        }
    }
    s1[j] = '\0';
}

int main() {
    char str1[] = "the quick brown fox jumps over the lazy dog";
    char str2[] = "opensesame!";
    printf("str2 = %s\n", str2);
    printf("Before squeeze: [%s]\n", str1);
    squeeze(str1, str2);
    printf("After squeeze : [%s]\n", str1);
    return 0;
}

