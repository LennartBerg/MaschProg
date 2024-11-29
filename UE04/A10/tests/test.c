#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../sample.h"
#include "../sensor_mock.h"

#define MAX_EXEC_TIME 2

#define MEAN_RESULT 1048
#define MED_RESULT 1049
#define MIN_RESULT -5943
#define MAX_RESULT 8043

int main() {
    clock_t time = clock();
    int tests[] = {1,1,1,1,1};

    sensor_mock_t sensor;
    sample_t sample;

    printf("Starting tests!\n");

    int val = 0;
    int mean = 0;
    int med = 0;
    int min = 0;
    int max = 0;

    printf("Starting mean test!\n");
    sample.size = 0;
    init(&sensor);
    setAfMean(&sample);

    while(available(&sensor)) {
        val = read(&sensor);
        if (add(val, &sample)) {
            mean += aggregate(&sample);
            sample.size = 0;
            add(val, &sample);
        }
    }
    if (mean == MEAN_RESULT)
        tests[1] = 0;
    else 
        printf("mean test: unexpected result - %d - FAILED\n", mean);

    printf("Starting median test!\n");
    sample.size = 0;
    init(&sensor);
    setAfMed(&sample);

    while(available(&sensor)) {
        val = read(&sensor);
        if (add(val, &sample)) {
            med += aggregate(&sample);
            sample.size = 0;
            add(val, &sample);
        }
    }
    if (med == MED_RESULT)
        tests[2] = 0;
    else 
        printf("median test: unexpected result - %d - FAILED\n", med);

    printf("Starting minimum test!\n");
    sample.size = 0;
    init(&sensor);
    setAfMin(&sample);

    while(available(&sensor)) {
        val = read(&sensor);
        if (add(val, &sample)) {
            min += aggregate(&sample);
            sample.size = 0;
            add(val, &sample);
        }
    }
    if (min == MIN_RESULT)
        tests[3] = 0;
    else 
        printf("minimum test: unexpected result - %d - FAILED\n", min);

    printf("Starting maximum test!\n");
    sample.size = 0;
    init(&sensor);
    setAfMax(&sample);

    while(available(&sensor)) {
        val = read(&sensor);
        if (add(val, &sample)) {
            max += aggregate(&sample);
            sample.size = 0;
            add(val, &sample);
        }
    }
    if (max == MAX_RESULT)
        tests[4] = 0;
    else 
        printf("maximum test: unexpected result - %d - FAILED\n", max);

    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;

    printf("RUNTIMETEST: Execution took %f seconds - ", seconds);
    if (seconds < MAX_EXEC_TIME) {
        tests[0] = 0;
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    return tests[0] | tests[1] | tests[2] | tests[3] | tests[4];
}