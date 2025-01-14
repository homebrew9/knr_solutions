/* We will use Bubble Sort technique to sort a large number of floating point
 * numbers that we read off from a text file. The text file has approximately
 * 100,000 numbers - one number per line and was generated using the following
 * commands:
 *     perl -le 'print rand foreach (1..106000)' > numlist
 *     perl -ne 'chomp; $x = sprintf("%.6f", $_); if (! defined $list{$x}) { print $x,"\n" } $list{$x}++' numlist | wc
 *     perl -ne 'chomp; $x = sprintf("%.6f", $_); if (! defined $list{$x}) { print $x,"\n" } $list{$x}++' numlist > tmp
 *     mv tmp numlist
 * Usage:
 *     ./bubblesort_v1 < numlist
 */

#include <stdio.h>
#define MAXSIZE 100000

int populateit(float *p, int len);
void sortit(float *nums, int len);
void printit(float *p, int len);

int main(int argc, char *argv[]) {
    float nums[MAXSIZE];
    int length;
    /* The return value of populateit is the number of elements read and
     * populated into the array "nums". The number of lines in the file may be
     * less than MAXSIZE, so we account for that possibility.
     */
    length = populateit(nums, MAXSIZE);
    sortit(nums, length);
    printit(nums, length);
}

int populateit(float *p, int len) {
    float flt;
    int result, size;
    size = 0;
    while (len-- > 0) {
        result = scanf("%f", &flt);
        /* scanf returns the "number of successful conversions". I see that it
         * returns 1 for successful reads and -1 for unsuccessful.
         */
        if (result != 1)
            break;
        size++;
        *p++ = flt;
        //printf("len = [%d], size = [%d], result = [%d], flt = [%f]\n", len, size, result, flt);
    }
    return size;
}

void sortit(float *nums, int len) {
    int i;
    float temp;
    while (len > 1) {
        for (i = 1; i < len; i++) {
            // If previous element is larger than current, then swap the two
            if (nums[i-1] > nums[i]) {
                temp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = temp;
            }
        }
        len--;
    }
}

void printit(float *p, int len) {
    /* It appears that if MAXSIZE is N, but only M (< N) elements of the float
     * array were populated, then the remaining (N - M) elements are 0. Hence
     * we can use the "while (*p)" test condition. However, it is an unreliable
     * test because it returns true if a data point itself is 0. So Plan B is to
     * pass the array length as parameter.
     */
    int i = 0;
    while (len-- > 0) {
        printf("nums[%7d] = %f\n", i, *p++);
        i++;
    }
}

