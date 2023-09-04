#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int br() {
    puts("---------------------------------------------------------------"); 
    return EXIT_SUCCESS; 
}

int main() {
    br(); 
    /* narrow types (e.g. bool or char) are promoted before arithmetic */
    bool my_false = false; 
    char a = 'a';

    puts("The narrow types are promoted to signed int before arithmetic: "); 
    printf("false is equal to %d; a is equal to %c\n", my_false, a); 
    printf("a + false is equal to %d\n", my_false + a);

    br();

    puts("The alphabet with a for loop: "); 
    for (int c = 97;  c != 123;  ++c) { //NB: cannot use size_t
        printf("%c", c); 
    }
    puts(""); 

    br();

    puts("The possible range of values for the types must include each other but it is not strict: "); 
    printf("The set of valid values for int goes from  %d to %d\n", INT_MIN, INT_MAX); 
    printf("THe set of valid values for long goes from %ld to %ld\n", LONG_MIN, LONG_MAX); 

    br(); 

    puts("Unsigned values round up"); 
    unsigned int x = 1; 
    printf("The unsigned value is %u, its negation is %u\n", x, -x); 

    br(); 

    puts("When the suffix L/UL/LL is not used, the compiler uses the first type that can contain the constant from a list: "); 

    unsigned long long x1 = 1000000UL * 4096UL; 
    unsigned long long x2 = 1000000 * 4096;
    printf("The value of 1000000 * 4096 with explicit stuff is %lld, without the explicit stuff is %lld\n", x1, x2);

    br(); 

    puts("Negative unsigned int becomes a large positive integer. "); 
    unsigned int x3 = -1U; 
    printf("In fact, -1U is equal to %u\n", x3); 

    return EXIT_SUCCESS;
}