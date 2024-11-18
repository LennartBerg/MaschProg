#include <stdio.h>
#include <time.h> 
#include "../memtools.h"

#define NUM_ARRAY_LEN 256

#define MAX_EXEC_TIME 1

int main() {
    int tests[] = {0,1,1,0,1};
    printf("Starting tests!\n");
    clock_t time = clock();

    int numbers[NUM_ARRAY_LEN];
    int chs = 0;
    for (size_t i = 0; i < NUM_ARRAY_LEN; ++i) {
        numbers[i] =  NUM_ARRAY_LEN - 1 - i;
        chs += NUM_ARRAY_LEN - 1 - i;
    }

    int ret = integersort(numbers, NUM_ARRAY_LEN);
    
    int i_numbers[NUM_ARRAY_LEN];
    int i_numbers_copy[NUM_ARRAY_LEN];

    long int l_numbers[NUM_ARRAY_LEN];
    long int l_numbers_copy[NUM_ARRAY_LEN];

    signed char c_numbers[NUM_ARRAY_LEN];
    signed char c_numbers_copy[NUM_ARRAY_LEN];


    for (size_t i = 0; i < NUM_ARRAY_LEN; ++i) {
        i_numbers[i] = i - (NUM_ARRAY_LEN/2);
        l_numbers[i] = i - (NUM_ARRAY_LEN/2);
        c_numbers[i] = i - (NUM_ARRAY_LEN/2);
    }

    size_t i_ret = memreverse(i_numbers, i_numbers_copy, sizeof(int), NUM_ARRAY_LEN);
    size_t l_ret = memreverse(l_numbers, l_numbers_copy, sizeof(long int), NUM_ARRAY_LEN);
    size_t c_ret = memreverse(c_numbers, c_numbers_copy, sizeof(char), NUM_ARRAY_LEN);

    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;

    printf("A) Integersort: \n");
    printf("Sorttest: ");
    for (size_t i = 0; i < NUM_ARRAY_LEN-1; ++i) {
        if (numbers[i] > numbers[i+1]) {
            ++tests[3];
            printf(" error at %u: %d > %d", i, numbers[i], numbers[i + 1]);
            break;
        }
    }
    if (tests[3] == 0) {
        printf(" - SUCCESS\n");
    } else {
        printf(" - FAILED\n");
    }
    printf("Checksumtest: ");
    if (ret != chs) {
        printf(" %d != %d - FAILED\n", ret, chs);
    } else {
        tests[4] = 0;
        printf(" - SUCCESS\n");
    }

    printf("B) Memreverse: \n");
    printf("Copytest: \n");
    for (size_t i = 0; i < NUM_ARRAY_LEN; ++i) {
        if (i_numbers[i] != i_numbers_copy[NUM_ARRAY_LEN - 1 - i]) {
            ++tests[0];
            printf(" error at int rev int: %d != %d\n", i_numbers[i], i_numbers_copy[NUM_ARRAY_LEN - 1 - i]);
        }
        if (l_numbers[i] != l_numbers_copy[NUM_ARRAY_LEN - 1 - i]) {
            ++tests[0];
            printf(" error at long rev long: %ld != %ld\n", l_numbers[i], l_numbers_copy[NUM_ARRAY_LEN - 1 - i]);
        }
        if (c_numbers[i] != c_numbers_copy[NUM_ARRAY_LEN - 1 - i]) {
            ++tests[0];
            printf(" error at char rev char: %d != %d\n", c_numbers[i], c_numbers_copy[NUM_ARRAY_LEN - 1 - i]);
        }

        if (tests[0] != 0) {
            break;
        }
    }
    if (tests[0] == 0) {
        printf(" - SUCCESS\n");
    } else {
        printf("Copytest - FAILED\n");
    }

    printf("Function returned %u, %u, %u - ", ret, l_ret, c_ret);

    if (i_ret == NUM_ARRAY_LEN * sizeof(int) &&
        l_ret == NUM_ARRAY_LEN * sizeof(long int) &&
        c_ret == NUM_ARRAY_LEN * sizeof(char)
    ) {
        tests[1] = 0;
        printf("return is correct - SUCCESS\n");
    } else {
        printf("return is wrong - FAILED\n");
    }
    printf("Execution took %f seconds - ", seconds);
    if (seconds < MAX_EXEC_TIME) {
        tests[2] = 0;
        printf("SUCCESS\n");
    } else {
        printf("FAILED\n");
    }

    return tests[0] | tests[1] | tests[2] | tests[3] | tests[4];
}