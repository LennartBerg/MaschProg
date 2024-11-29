#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "../ll.h"

#define MAX_EXEC_TIME 1
#define BUFSIZE 1024
#define NUM_CMD 1

typedef struct exec_t {
    int ret;
    char cmd[256];
    char test[256];
} exec_t;

int main() {
    clock_t time = clock();
    int tests[] = {0,1};

    printf("Starting tests!\n");

    /* create root node */
    struct Node* root = createNode(0);

    /* insert 30 elements */
    int i;
    for (i = 1; i < 32; i++) {
        append(root, createNode(i));
    }

    i = 0;
    struct Node* cur = root;
    while (1) {
        /* sanity check */
        if (cur == NULL) {
            printf("ERROR: cannot check because current is NULL\n");
            tests[0] = 1;
            return 1;
        }

        /* check expected value */
        if (getValue(cur) != i) {
            printf("ERROR: the expected value %d was not received, instead %d was"
                "found\n", i, getValue(cur));
            tests[0] = 1;
            break;
        }

        /* step to next or break */
        i++;
        if (hasNext(cur))
            cur = getNext(cur);
        else
            break;
    }

    if (tests[0] == 1) return 1;
    
    /* check if all elements present */
    if (i != 32) {
        printf("ERROR: not enough elements in the list\n");
        return 1;
    }

    for (size_t j = getLength(root)-1; j-- > 0; ) {
        if (getValueAt(root,j) % 2 == 0) {
            removeAt(root,j);
        }
    }
    
    cur = root;
    i = 1;
    int v = 1;
    while (hasNext(cur))
    {
        v += 2;
        cur = getNext(cur);
        if (v != getValue(cur)){
            printf("ERROR: unexpected value of %d in list at index %d\n", getValue(cur), i);
            tests[0] = 1;
        }
        ++i;
    }
    

    if (i != 16) {
        printf("ERROR: number of elements in the list is incorrect\n");
        tests[0] = 1;
    }

    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;

    printf("RUNTIMETEST: Execution took %f seconds - ", seconds);
    if (seconds < MAX_EXEC_TIME) {
        tests[1] = 0;
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    return tests[0] | tests[1];
}