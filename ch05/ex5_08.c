/* There is no error checking in day_of_year or month_day.
 * Remedy this defect.
 */
#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month and day */
/* Leap year algorithm:
 * ----------------------
 * If Y is div by 4, but not div by 100, then it is a leap year.
 * If Y is div by 4 and also by 100, then it must also be
 * div by 400 to be a leap year.
 * Examples:
 * ------------
 * Y = 1988. Div by 4 but not by 100, hence it is a leap year.
 * Y = 2000. Div by 4 and also by 100. Is it div by 400? Yes, so leap year.
 * Y = 1700. Div by 4 and also by 100. Is it div by 400? No, so not a leap year.
 * Y = 1800. Not a leap year, because div by 4 and 100, but not by 400
 * Y = 1900. Not a leap year, because div by 4 and 100, but not by 400
 * In C, boolean values are integers. T = 1 and F = 0. Also, && operator has higher
 * precedence than || operator.
 * Consider the expression: Y%4 == 0 && Y%100 != 0 || Y%400 == 0
 * Now, "Y%4 == 0 && Y%100 != 0" means "div by 4 and not div by 100". As long
 * as this compound expression is true, the year is a leap year and it won't bother
 * with evaluating the last expression. (Eg. 1988, 1992, 1996).
 * If "Y%4 == 0 && Y%100 != 0" is false, then it means that Y is div by 4 and it is
 * **ALSO DIV BY** 100. So, for such a year, we evaluate the last expression ie. Y%400 == 0.
 * The outcome of the last condition is the outcome for the year. Eg. 2000, it is div by 4
 * and also by 100. The first compound condition is false in that case. So, the last condition
 * is evaluated. Is Y%400 == 0 ie. is 2000%400 == 0 true? Yes, it is true here. So, 2000 is leap.
 * Sample runs:
 * ----------------
 * Y%4 == 0 && Y%100 != 0 || Y%400 == 0
 * Y = 1988 => 1988%4 == 0 && 1988%100 != 0 || 1988%400 == 0 => T && T => T (short-circuit)
 * Y = 1992 => 1992%4 == 0 && 1992%100 != 0 || 1992%400 == 0 => T && T => T (short-circuit)
 * Y = 1996 => 1996%4 == 0 && 1996%100 != 0 || 1996%400 == 0 => T && T => T (short-circuit)
 * Y = 2000 => 2000%4 == 0 && 2000%100 != 0 || 2000%400 == 0 => T && F || T => F || T => T
 * Y = 1700 => 1700%4 == 0 && 1700%100 != 0 || 1700%400 == 0 => T && F || F => F || F => F
 * Y = 1800 => 1800%4 == 0 && 1800%100 != 0 || 1800%400 == 0 => T && F || F => F || F => F
 * Y = 1900 => 1900%4 == 0 && 1900%100 != 0 || 1900%400 == 0 => T && F || F => F || F => F
 */

int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    /* boundary value checks for year, month, day */
    if (year <= 0 || month <= 0 || day <= 0 || day > daytab[leap][month]) {
        return -1;
    }
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    /* boundary value checks for year and yearday */
    if (year <= 0 || yearday <= 0 || leap && yearday > 366 || !leap && yearday > 365) {
        *pmonth = -1;
        *pday = -1;
        return;
    } 
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}

int main(void) {
    int y, m, d, doy, yd;
    y = 1988;
    yd = 60;
    month_day(y, yd, &m, &d);
    printf("(y, yd) = (%d, %3d) ; (m, d) = (%2d, %2d)\n", y, yd, m, d);

    y = 1988;
    yd = 367;
    month_day(y, yd, &m, &d);
    printf("(y, yd) = (%d, %3d) ; (m, d) = (%2d, %2d)\n", y, yd, m, d);

    y = 1988;
    m = 3;
    d = 1;
    doy = day_of_year(y, m, d);
    printf("(y, m, d) = (%d, %2d, %2d) ; doy = %3d\n", y, m, d, doy);

    y = 1987;
    m = 2;
    d = 30;
    doy = day_of_year(y, m, d);
    printf("(y, m, d) = (%d, %2d, %2d) ; doy = %3d\n", y, m, d, doy);
}

