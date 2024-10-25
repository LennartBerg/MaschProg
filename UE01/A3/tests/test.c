#include <stdio.h>
#include <time.h> 
#include "../smallestNumber.h"

#define RET_VALUE 0x377836150D76639
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
    unsigned long result = smallestNumber();
    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;
    printf("Function returned %lu - ", result);
    char input[16];
    sprintf(input,"%lu", result);
    unsigned long hashed_result = hash(input);

    if (hashed_result == RET_VALUE) {
        tests[0] = 0;
        printf("SUCCESS\n");
    } else {
        printf("FAILED\n");
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