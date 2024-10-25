#include "smallestNumber.h"

#define START 1
#define END 20

unsigned long leastCommonMultiple(unsigned long a, unsigned long b) {
    unsigned long max, lcm;

    max = (a > b) ? a : b;
    lcm = max;

    while (lcm % a != 0 || lcm % b != 0) {
        lcm += max;
    }

    return lcm;
}

unsigned long smallestNumber(void) {
    unsigned long lcm = 1;
    for (int n = START; n <= END; n++) {
        lcm = leastCommonMultiple(lcm, n);
    }
    return lcm;
}