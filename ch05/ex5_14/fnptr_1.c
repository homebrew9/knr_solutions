/* Yet another program that makes use of function pointers.
 * By: r2d2
 * On: 6-Jul-2015
 */
#include <stdio.h>
#include <math.h>

double calc_sin(double x);
double calc_cos(double x);
double calc_tan(double x);
double calc_sqrt(double x);
double calc_sqr(double x);
double add_ssq_csq(double x, double (*fn_sqr)(double), double (*fn_sin)(double), double (*fn_cos)(double));
void generate_table( double start,
                     double end,
                     double incr,
                     double (*fn_sin)(double),
                     double (*fn_cos)(double),
                     double (*fn_tan)(double),
                     double (*fn_sqrt)(double),
                     double (*fn_sqr)(double),
                     double (*fn_ssq_csq)(double, double (*fn_sqr)(double), double (*fn_sin)(double), double (*fn_cos)(double))
                   );

int main(int argc, char *argv[]) {
    double s = 0;
    double e = 5;
    double i = 0.1;
    generate_table( s, e, i,
                    (*calc_sin),
                    (*calc_cos),
                    (*calc_tan),
                    (*calc_sqrt),
                    (*calc_sqr),
                    (*add_ssq_csq)
                  );
}

void generate_table( double start,
                     double end,
                     double incr,
                     double (*fn_sin)(double),
                     double (*fn_cos)(double),
                     double (*fn_tan)(double),
                     double (*fn_sqrt)(double),
                     double (*fn_sqr)(double),
                     double (*fn_ssq_csq)(double, double (*fn_sqr)(double), double (*fn_sin)(double), double (*fn_cos)(double))
                   )
{
    printf("Start = %f\n", start);
    printf("End   = %f\n", end);
    printf("Incr  = %f\n", incr);
    printf("+----------+---------------+---------------+---------------+---------------+--------------+---------------+\n");
    printf("|    x     |     sin(x)    |     cos(x)    |     tan(x)    |    sqrt(x)    |    sqr(x)    |    ssq_csq    |\n");
    printf("+----------+---------------+---------------+---------------+---------------+--------------+---------------+\n");
    while (start <= end) {
        printf( "|%9.4f | %10.6f    | %10.6f    | %10.6f    | %10.6f    | %10.6f   | %10.6f    |\n",
                start,
                (*fn_sin)(start),
                (*fn_cos)(start),
                (*fn_tan)(start),
                (*fn_sqrt)(start),
                (*fn_sqr)(start),
                (*fn_ssq_csq)(start, (**fn_sqr), (**fn_sin), (**fn_cos))  /* "(*fn_ssq_csq)(start, (*calc_sqr), (*calc_sin), (*calc_cos))" is legal as well */ 
              );
        start += incr;
    }
    printf("+----------+---------------+---------------+---------------+---------------+--------------+---------------+\n");
}

double calc_sin(double x) { return sin(x); }
double calc_cos(double x) { return cos(x); }
double calc_tan(double x) { return tan(x); }
double calc_sqrt(double x) { return sqrt(x); }
double calc_sqr(double x) { return x*x; }

double add_ssq_csq(double x, double (*fn_sqr)(double), double (*fn_sin)(double), double (*fn_cos)(double)) {
    return (*fn_sqr)((*fn_sin)(x)) + (*fn_sqr)((*fn_cos)(x));
}

