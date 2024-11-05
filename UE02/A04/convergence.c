#include "convergence.h"

#define MAX 1000000

long collatz(long n) {
    if ((n & 0b1) == 0) {
        return n >> 1;
    }
    return 3 * n + 1;
}

int convergence(unsigned int result[]) {
    unsigned int memo[MAX] = {0};
    unsigned long n;
    unsigned int l;
    for (unsigned int i = 1; i <= MAX; i++) {
        l = 1;
        n = i;
        while (n != 1) {
            if (n <= MAX && memo[n - 1] != 0) {
                l += memo[n - 1] - 1;
                break;
            }
            n = collatz(n);
            l++;
        }
        memo[i - 1] = l;
        if (l > result[1]) {
            result[0] = i;
            result[1] = l;
        }
    }
    return result[0];
}