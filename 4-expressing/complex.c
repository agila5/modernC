#include <stdlib.h>
#include <stdio.h>
#include <tgmath.h>

/* Test ternary operator and complex numbers */
double complex sqrt_real(double x) {
  /* For some reason I cannot use CMPLX(...) as displayed in the book*/
  return (x < 0) ? (0 + sqrt(-x) * I) : (sqrt(x) + 0 * I);
}

int print_sqrt(double x) {
  double complex sqrt_x = sqrt_real(x);
  printf(
    "x = %+.1f and its 'generalised' square root is %.2f%+.2fi\n", 
    x,
    creal(sqrt_x), 
    cimag(sqrt_x)
  );
  return EXIT_SUCCESS;
}


int main() {
  print_sqrt(3);
  print_sqrt(-3);

  return EXIT_SUCCESS;
}