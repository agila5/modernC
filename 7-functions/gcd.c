#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <errno.h>

long to_long(char* input) {
    errno = 0; 
    char *end; 
    long digit = strtol(input, &end, 10); 

    const bool range_error = errno == ERANGE; 
    if (range_error) {
        perror("strtol");
        exit(EXIT_FAILURE);  
    }

    const bool no_digits_error = end == input;     
    if (no_digits_error) {
        puts("No digits were found :("); 
        exit(EXIT_FAILURE); 
    }

    return digit; 
}

long x = 30 % 18; 

long compute_gcd(long a, long b) {
    /*
    Given two integers a, b > 0, the gcd is defined as the greatest integer c > 0 that divides both a and b. Here is the formula: 

                                     gcd(a, b) = max{c in N: c|a and c|b}

    If we also assume that a < b, we can see that gcd(a, b) = gcd(a, b % a). For example
    - gcd(5, 10) = gcd(5, 0) so that gcd(5, 10) = 5; 
    - gcd(5, 9) = gcd(5, 4) = (flip) = gcd(4, 5) = gcd(4, 1) = 1
    - gcd(18, 30) = gcd(18, 12) = (flip) = gcd(12, 18) = gcd(12, 6) = (flip) = gcd(6, 12) = 
    gcd(6, 0) = (flip) = gcd(0, 6) = 6
    */
    if (a == 0) {
        return b; 
    }
    long rem = b % a; 
    return compute_gcd(rem, a); 
}

/* Not sure about the following :'|*/
void swap(long* a, long* b) {
    long tmp = *a; 
    *a = *b; 
    *b = tmp; 
}

int main(int argc, char* argv[argc + 1]) {
    assert(argc == 3);     
    long a = to_long(argv[1]);
    long b = to_long(argv[2]);
    /* We need to be sure that a < b otherwise the algorithm describe before doesn't work*/
    if (a > b) {
        swap(&a, &b); 
    }
      
    printf("The gcd between a = %li and b = %li is %li", a, b, compute_gcd(a, b)); 
    
    return EXIT_SUCCESS; 
}
