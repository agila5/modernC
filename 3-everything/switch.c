#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[argc + 1]) {
    long int li = strtol(argv[1], NULL, 10);

    switch (li) {
        default: puts("++++ ---- ++++");
        case 4: puts("++++"); 
        case 3: puts("+++"); 
        case 2: puts("++");
        case 1: puts("+");
        case 0: puts("");
    }
    
    return EXIT_SUCCESS;
}