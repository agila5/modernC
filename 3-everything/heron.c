#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* lower and upper iteration limits centred around 1.0 */
static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char *argv[argc + 1])
{
    /* 
    Taken from 
    - argv and argc are how command line arguments are passed to main() in C and C++.
    - argc will be the number of strings pointed to by argv. This will (in practice) 
      be 1 plus the number of arguments, as virtually all implementations will prepend 
      the name of the program to the array.
    - The variables are named argc (argument count) and argv (argument vector) by 
      convention, but they can be given any valid identifier: 
      int main(int num_args, char** arg_strings) is equally valid.   
    */
    for (int i = 1; i < argc; ++i)
    {                                        // process args
        double const a = strtod(argv[i], 0); // arg -> double
        double x = 1.0;
        /* Metodo della bisezione per avere un'approssimazione grezza di 1/a */
        while (true)
        {
            double prod = a * x;
            if (prod < eps1m01)
            {
                x *= 2.0;
            }
            else if (prod > eps1p01)
            {
                x *= 0.5;
            }
            else
            {
                break;
            }
        }

        printf("intermediate value: a=%.2f,\tx=%.2f,\ta*x=%.5f\n", a, x, a * x);

        while (true)
        /* 
        Metodo di Newton per trovare lo zero della funzione f(x) = 1/x - a. 
        Infatti si ha che f'(x) = -1/x^2 e, quindi, 
                x_(n+1) = x_n - (1/x_n - a) / (-1/x_n^2) 
                        = x_n + x_n - a * x_n ^ 2
                        = 2x_n - a * x_n ^ 2
                        = x_n * (2 - a * x_n)
        */
        {
            double prod = a * x;
            if ((prod < eps1m24) || (eps1p24 < prod))
            {
                x *= (2.0 - prod);
            }
            else
            {
                break;
            }
        }

        printf("final value: a=%.2f,\tx=%.2f,\ta*x=%.12f\n", a, x, a * x);
        puts("--------------------------------");
    }
}