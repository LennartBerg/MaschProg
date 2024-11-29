#include "friends.h"

#include <stdio.h>

#define MAX 1000000
#define FCNT 256
#define BUFSIZE 8196

int main(void) {
    friend_t friends[FCNT] = {0};
    friend_t* fIdx = friends;

    char buffer[BUFSIZE];
    char* bIdx = buffer;

    unsigned int sums[MAX] = {0};
    unsigned int fsum = sumFriends(friends, FCNT, sums, MAX);

    while (fIdx->a != 0 && bIdx < (buffer+BUFSIZE)) {
        bIdx += sprintf(bIdx, "( %u | %u )\n", fIdx->a, fIdx->b);
        ++fIdx;
    }
    bIdx += sprintf(bIdx, "Sum of friends: %u", fsum);
    puts(buffer);
    return 0;
}
