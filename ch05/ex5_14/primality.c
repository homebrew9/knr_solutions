/* A program to determine if a number if prime or not. We use the standard
 * divisibility test up to square root for this. This method becomes impractical
 * for large numbers because the number of primes up to the square root of a
 * number increases rapidly as the number grows.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#define DEFAULT_NUM 1000012337
#define MAXELEM 100
#define MAXLEN 40 

int num[MAXELEM];
int max_index = -1;
int is_prime(int n);

int main(int argc, char *argv[]) {
    //printf("num[%d] = %d\n", max_index, num[max_index]);
    //printf("argc = %d\n", argc);
    if (argc > 1) {
        while (--argc) {
            //printf("argc = [%d], argv = [%s]\n", argc, *++argv);
            max_index++;
            num[max_index] = atoi(*++argv);
        }
    } else {
        max_index++;
        num[max_index] = DEFAULT_NUM;
    }

    int result;
    int i;
    char msg[MAXLEN];
    for (i = 0; i <= max_index; i++) {
        if (num[i] <= 0) {
            //strcpy(msg, "Skipped. Number must be >= 1.");
            strcpy(msg, "Skipped.");
        } else if (num[i] == 1) {
            strcpy(msg, "Neither prime nor composite.");
        } else {
            result = is_prime(num[i]);
            if (result == 1) {
                strcpy(msg, "is prime.");
            } else {
                //strcpy(msg, "is composite.");
                strcpy(msg, "");
            }
        }
        printf("%15d : %s\n", num[i], msg);
    }
}

int is_prime(int n) {
    int rem;
    int i;
    int end = sqrt(n);
    //printf("end = %d\n", end);
    /* 0 = FALSE i.e. n is not prime.
     * 1 or higher = TRUE i.e. n is prime.
     * We start with the assumption that n is prime. And we try to disprove it inside the "for" loop.
     */
    int rslt = 1;
    for (i = 2; i <= end; i++) {
        rem = n % i;
        //printf("\tn = %5d, i = %5d, rem = %5d => %s\n", n, i, rem, (rem == 0) ? "Divisible" : "Not divisible");
        if (rem == 0) {
            rslt = 0;
            break;
        }
    }
    return rslt;
}

