#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <errno.h>

long long to_long(char* input) {
    errno = 0; 
    char *end; 
    long long digit = strtoll(input, &end, 10); 

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

long long fib(long long n) {
    if (n < 3) {
        return 1; 
    }
    return fib(n - 1) + fib(n - 2); 
}; 

int main(int argc, char* argv[argc + 1]) {
    assert(argc == 2);
    long long n = to_long(argv[1]);
    assert(n >= 0);  

    printf("The first %lli digits of the Fibonacci sequence are: \n", n); 
    for (long long i = 1; i <= n; ++i)
    {
        printf("%lli ", fib(i)); 
    }
   
    return EXIT_SUCCESS; 
}