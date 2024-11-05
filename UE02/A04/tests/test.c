#include <stdio.h>
#include <time.h> 
#include "../convergence.h"

#define RET_VALUE 0x3778b0f8ca9122c
#define MAX_EXEC_TIME 0.1
#define MIN_EXEC_TIME 0.000005

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash ;
}

int main() {
    int tests[] = {1,1,1};
    printf("Starting tests!\n");
    clock_t time = clock();
    unsigned int result[2];
    int ret = convergence(result);
    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;
    printf("Function returned %d - ", ret);
    char input[16];
    sprintf(input,"%u%u", result[0],result[1]);
    unsigned long hashed_result = hash(input);
    if (hashed_result == RET_VALUE) {
        tests[0] = 0;
        printf("result is correct - SUCCESS\n");
    } else {
        printf("result is wrong - FAILED\n");
    }
    printf("Execution took %f seconds - ", seconds);
    if (seconds < MAX_EXEC_TIME) {
        tests[1] = 0;
        printf("SUCCESS\n");
    } else {
        printf("FAILED\n");
    }
    printf("Anticheat: ");
    if (seconds > MIN_EXEC_TIME) {
        tests[2] = 0;
        printf("- SUCCESS\n");
    } else {
        printf("execution time to small - FAILED\n");
    }
    printf("End tests!\n");

    return tests[0] | tests[1] | tests[2];
}