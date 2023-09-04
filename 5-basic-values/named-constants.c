#include <stdlib.h>
#include <stdio.h>

#define M_PI 3.14159
#define CORVID_NAME                \
(char const*const[corvid_num]){    \
    [chough] = "chough"            \
}                                  \

int main () {
    enum corvid {jay, magpie , raven, chough, corvid_num, }; 
    char const*const bird[corvid_num] = {
        [raven] = "raven", 
        [magpie] = "magpie", 
        [jay] = "jay", 
    }; 

    for (size_t i = 0; i < corvid_num; ++i) {
        /* NB: They are printed in the same order as they are specified in the enum*/
        printf("Corvid %zu is the %s\n", i, bird[i]); 
    }
 
    printf("Using a MACRO, we can see that the value of PI is %f\n", M_PI); 
    printf("And, finally, CORVID_NAME[3] is equal to %s (the other elements are (null)...)", CORVID_NAME[3]); 

    return EXIT_SUCCESS; 
}