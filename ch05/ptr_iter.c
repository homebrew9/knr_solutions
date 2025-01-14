/* A short program to create an array of strings and a pointer to the last
 * element. Then use the pointer to walk through the array from the last to
 * the first element.
 * (Could not get that working. Looks like we will have to keep a record of
 *  the highest index as a static int.)
 */
#include <stdio.h>
#define MAXLEN 7

int main(void) {
    char *args[MAXLEN];

    args[0] = "Monday";
    args[1] = "Tuesday";
    args[2] = "Wednesday";
    args[3] = "Thursday";
    args[4] = "Friday";
    args[5] = "Saturday";
    args[6] = "Sunday";

    int i;
    printf("\n");
    for (i = 0; i < MAXLEN; i++) {
        printf("%u %s\n", &args[i], args[i]);
    }
}

