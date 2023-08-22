#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[argc + 1]) {
    /* 
    strtol is a function that converts a byte string (pointed to by the first 
    argument) to an integer. It should be an enhanced version of atoi since it
    returns an informative output in case of error. In fact, 
    > If the str is empty or does not have the expected form, no conversion is 
    > performed, and (if str_end is not a null pointer) the value of str is 
    > stored in the object pointed to by str_end.
    */
    long li = strtol(argv[1], NULL, 10);

    /* NB: The expression defining the switch statement (i.e. (li)) can be 
    any expression of integer type, so not only int but also char, unsigned, 
    long, long long and I don't need type casting.*/

    switch (li) {
        /* The following works since 
        > once we have run into the block, execution continues until it reaches
        > a break or the end of the block. In this case, there are no break 
        > statements, we end up running all subsequent puts statements. For 
        > example, the output when li is equal to 3 is a triangle with three
        > lines
        > ***
        > **
        > *
        */
        default: puts("++++ ---- ++++");
        case 4: puts("++++"); 
        case 3: puts("+++"); 
        case 2: puts("++");
        case 1: puts("+");
    }
    
    return EXIT_SUCCESS;
}