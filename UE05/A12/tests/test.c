#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../friends.h"

#define MAX_EXEC_TIME 2

#define MAX 1000000
#define FCNT 256

int main() {
    clock_t time = clock();
    int tests[] = {1,1,1};

    printf("Starting tests!\n");
    friend_t friends[FCNT] = {0};
    friend_t* fIdx = friends;

    unsigned int sums[MAX] = {0};
    unsigned int fsum = sumFriends(friends, FCNT, sums, MAX);
    unsigned int cnter = fsum;
    unsigned int fcnt = 0;

    if (fsum == 25275024)
        tests[0] = 0;
    else
        printf("error: friendssum of %u is incorrect\n", fsum);

    while (fIdx->a != 0) {
        ++fcnt;
        ++fIdx;
    }

    if (fcnt == 80)
        tests[1] = 0;
    else
        printf("error: number of found friend %u is incorrect\n", fcnt);

    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;

    printf("RUNTIMETEST: Execution took %f seconds - ", seconds);
    if (seconds < MAX_EXEC_TIME) {
        tests[2] = 0;
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    return tests[0] | tests[1] | tests[2];
}