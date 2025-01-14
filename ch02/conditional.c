/* A few code snippets from Section 2.11 of KnR. This is regarding conditional
 * expressions involving the ternary operator.
 */
#include <stdio.h>
int main(void) {
    // Case 1: The length of the array is known beforehand
    int n = 43;
    char s[43] = "the quick brown fox jumps over the lazy dog";
    int i;
    for (i = 0; i < n; i++) {
        // KnR has this line: printf("%6d%c", a[i], (i%10==9 || i==n-1) > '\n' : ' ');
        // I think that is for *number* arrays. I've modified it a bit below, but I cannot
        // print the blank character '' so I print '|' character.
        printf("%c%c", s[i], (i%10==9 || i==n-1) ? '\n' : '|');
    }

    // Case 2: The length of the array is not known beforehand
    printf("\n================================================\n\n");
    char gettysburg[] = "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal. Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and dedicated, can long endure. We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live. It is altogether fitting and proper that we should do this. But, in a larger sense, we can not dedicate -- we can not consecrate -- we can not hallow -- this ground. The brave men, living and dead, who struggled here, have consecrated it, far above our poor power to add or detract. The world will little note, nor long remember what we say here, but it can never forget what they did here. It is for us the living, rather, to be dedicated here to the unfinished work which they who fought here have thus far so nobly advanced. It is rather for us to be here dedicated to the great task remaining before us -- that from these honored dead we take increased devotion to that cause for which they gave the last full measure of devotion -- that we here highly resolve that these dead shall not have died in vain -- that this nation, under God, shall have a new birth of freedom -- and that government of the people, by the people, for the people, shall not perish from the earth.";
    int iter = 0;
    int len = 80;
    while (gettysburg[iter] != '\0') {
        printf("%c%s", gettysburg[iter], (iter%len==len-1) ? "\n" : "");
        iter++;
    }
    printf("\n");

    return 0;
}

