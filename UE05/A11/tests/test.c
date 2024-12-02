#include <stdio.h>
#include <time.h>

#include "../memtools.h"

#define TEST_VAL {0, -1, 1, 2147483647, -2147483648, -2147483647, 2147483646}
#define TEST_INT_RES {0, -1, 16777216, -129, 128, 16777344, -16777345}
#define TEST_LON_RES {0L, -1L, 72057594037927936L, -554050781184L, 554050781183L, 72058148088709119L, -72058148088709120L}

#define TEST_CNT 7

#define MAX_EXEC_TIME 1

int main() {
    int tests[] = {1, 0, 0, 0, 0};
    printf("Starting tests!\n");
    clock_t time = clock();

    int is_little = isLittleEndian();
    int a[TEST_CNT] = TEST_VAL;
    long al[TEST_CNT] = TEST_VAL;
    int b[TEST_CNT];
    long c[TEST_CNT];
    long d[TEST_CNT];
    int e[TEST_CNT];
    int res_int[TEST_CNT] = TEST_INT_RES;
    long res_long[TEST_CNT] = TEST_LON_RES;

    for (size_t i = 0; i < TEST_CNT; ++i) {
        convertLEtoBE(&a[i], &b[i], sizeof(a[i]));
        convertBEtoLE(&b[i], &e[i], sizeof(b[i]));
        broaden(&a[i], &c[i], sizeof(a[i]), sizeof(c[i]), 1, is_little);
        broaden(&b[i], &d[i], sizeof(b[i]), sizeof(d[i]), 1, !is_little);

        if (b[i] != res_int[i]) {
            printf("error at conversion %d between LE and BE: %d should be %d\n", a[i], b[i], res_int[i]);
            ++tests[1];
        }
        if (c[i] != al[i]) {
            printf("error at broaden LE int to long: %ld should be %ld\n", c[i], al[i]);
            ++tests[2];
        }
        if (d[i] != res_long[i]) {
            printf("error at broaden BE int to long: %ld should be %ld\n", d[i], res_long[i]);
            ++tests[3];
        }
        if (e[i] != a[i]) {
            printf("error at back conversion between LE and BE: %d should be %d\n", e[i], a[i]);
            ++tests[4];
        }
    }

    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;

    if (tests[1])
        printf("conversion between Little and Big Endian FAILED\n");
    if (tests[2])
        printf("broaden LE from int to long FAILED\n");
    if (tests[3])
        printf("broaden BE from int to long FAILED\n");
    if (tests[4])
        printf("back conversion between Little and Big Endian FAILED\n");

    printf("Execution took %f seconds - ", seconds);
    if (seconds < MAX_EXEC_TIME) {
        tests[0] = 0;
        printf("SUCCESS\n");
    } else {
        printf("FAILED\n");
    }

    return tests[0] | tests[1] | tests[2] | tests[3] | tests[4];
}