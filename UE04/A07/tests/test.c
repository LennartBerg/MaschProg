#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXEC_TIME 1
#define BUFSIZE 1024
#define NUM_CMD 9

typedef struct exec_t {
    int ret;
    char cmd[256];
    char test[256];
} exec_t;

int main() {
    clock_t time = clock();
    int tests[] = {1, 0, 0};
    exec_t testexe[] = {
        {0,
         "../A07 -2 + 1",
         "-2 + 1 = -1\n"},
        {0,
         "../A07 1 - 1",
         "1 - 1 = 0\n"},
        {0,
         "../A07 7 \\* 4",
         "7 * 4 = 28\n"},
        {0,
         "../A07 49 / 7",
         "49 / 7 = 7\n"},
        {0,
         "../A07 17 % 3",
         "17 % 3 = 2\n"},
        {1,
         "../A07 a + 1",
         ""},
        {1,
         "../A07 1 + b",
         ""},
        {1,
         "../A07 a 2 1",
         ""},
        {1,
         "../A07 a + 1 1",
         ""}};

    printf("Starting tests!\n");

    for (int i = 0; i < NUM_CMD; ++i) {
        char buf[BUFSIZE] = {0};
        char output[BUFSIZE] = {0};
        FILE *fp;

        if ((fp = popen(testexe[i].cmd, "r")) == NULL) {
            printf("FATAL: Could not execute binary. Testing failed\n");
            return -1;
        }

        unsigned int idx = 0;
        while (fgets(buf, BUFSIZE, fp) != NULL) {
            sprintf(output + idx, "%s", buf);
            idx = strlen(output);
        }
        if (strcmp(testexe[i].test, "")) {
            if (strcmp(testexe[i].test, output)) {
                printf("OUTPUTTEST-%d: ouput is wrong: %s - FAILED\n", i + 1, output);
                tests[1] = 1;
            } else {
                printf("OUTPUTTEST-%d: output is correct - PASSED\n", i + 1);
            }
        }

        int status = pclose(fp);
        int ret = WEXITSTATUS(status);

        if (ret == testexe[i].ret) {
            printf("RETVALTEST-%d: exit value is correct - PASSED\n", i + 1);
        } else {
            printf("RETVALTEST-%d: exit value '%d' is wrong - FAILED\n", i + 1, ret);
            tests[2] = 1;
        }
    }

    time = clock() - time;
    double seconds = ((double)time) / CLOCKS_PER_SEC;

    printf("RUNTIMETEST: Execution took %f seconds - ", seconds);
    if (seconds < MAX_EXEC_TIME) {
        tests[0] = 0;
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    return tests[0] | tests[1] | tests[2];
}