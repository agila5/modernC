#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[argc + 1]) {
    long int li = strtol(argv[1], NULL, 10);

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