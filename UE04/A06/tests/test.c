#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXEC_TIME 1
#define BUFSIZE 1024
#define TESTCMD "../A06 eins zwei drei vier fünf sechs sieben acht neun zehn"
#define TESTSTR "../A06\neins\nzwei\ndrei\nvier\nfünf\nsechs\nsieben\nacht\nneun\nzehn\n"
#define RETVAL 11

int main() {
    int tests[] = {1, 1, 1};
    printf("Starting tests!\n");
    clock_t time = clock();
    char *cmd = TESTCMD;    
    char buf[BUFSIZE] = {0};
    char input[] = TESTSTR;
    char output[BUFSIZE] = {0};
    FILE *fp;

    if ((fp = popen(cmd, "r")) == NULL) {
        printf("FATAL: Could not execute binary. Testing failed\n");
        return -1;
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

    unsigned int idx = 0;
    while (fgets(buf, BUFSIZE, fp) != NULL) {
        sprintf(output + idx,"%s", buf);
        idx = strlen(output);
    }
    if (strcmp(input,output)) {
        printf("OUTPUTTEST: ouput is wrong: %s\n - FAILED\n", output);
    } else {
        printf("OUTPUTTEST: output is correct - PASSED\n");
        tests[1] = 0;
    }
    
    int status = pclose(fp);
    int ret = WEXITSTATUS(status);

    if (ret == RETVAL) {
        printf("RETVALTEST: exit value is correct - PASSED\n");
        tests[2] = 0;
    } else {
        printf("RETVALTEST: exit value '%d' is wrong - FAILED\n",ret);
    }

    return tests[0] | tests[1] | tests[2];
}