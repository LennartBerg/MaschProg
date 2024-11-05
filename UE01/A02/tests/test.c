#include <math.h>
#include <stdio.h>
#include <time.h>

#include "../printTypes.h"
#include "lib/cJSON/cJSON.h"

#define TYPES {"signed char", "unsigned char", "signed short", "unsigned short", "signed int", "unsigned int", "signed long", "unsigned long"}
#define BITWIDTH_MIN 0
#define BITWIDTH_MAX 128

typedef struct Type_t {
    double min;
    double max;
    double bits;
} Type_t;

int main() {
    char buffer[2048];
    printTypesToJson(buffer);

    cJSON *json = cJSON_Parse(buffer);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("FAILED - JSON format error before: %s\n", error_ptr);
        }
        return 1;
    }

    size_t result = 0;
    int ret = 0;
    Type_t types[8];
    char *names[] = TYPES;

    printf("start JSON format test\n");
    for (size_t i = 0; i < 8; ++i) {
        const cJSON *item = cJSON_GetObjectItem(json, names[i]);
        if (item == NULL) {
            printf("object \"%s\" not found\n", names[i]);
            ++result;
        } else {
            const cJSON *min = cJSON_GetObjectItem(item, "min");
            if (min == NULL) {
                printf("param \"min\" of Object \"%s\" not found\n", names[i]);
                ++result;
            } else if (!cJSON_IsNumber(min)) {
                printf("param \"min\" of Object \"%s\" is not a number\n", names[i]);
                ++result;
            } else {
                types[i].min = min->valuedouble;
            }
            const cJSON *max = cJSON_GetObjectItem(item, "max");
            if (max == NULL) {
                printf("param \"max\" of Object \"%s\" not found\n", names[i]);
                ++result;
            } else if (!cJSON_IsNumber(max)) {
                printf("param \"max\" of Object \"%s\" is not a number\n", names[i]);
                ++result;
            } else {
                types[i].max = max->valuedouble;
            }
            const cJSON *bits = cJSON_GetObjectItem(item, "bits");
            if (bits == NULL) {
                printf("param \"bits\" of Object \"%s\" not found\n", names[i]);
                ++result;
            } else if (!cJSON_IsNumber(bits)) {
                printf("param \"bits\" of Object \"%s\" is not a number\n", names[i]);
                ++result;
            } else {
                types[i].bits = bits->valuedouble;
            }
        }
    }
    if (result != 0) {
        printf("JSON format test - FAILED\n");
        return 1;
    }
    printf("JSON format test - PASSED\nstart bounds test\n");
    for (size_t j = 0; j < 8; ++j) {
        if (types[j].min >= types[j].max) {
            printf("ERROR: type \"%s\" - min:%.0f >= max:%.0f\n", names[j], types[j].min, types[j].max);
            ++result;
        }
        if (j % 2 == 1) {
            if (((int)types[j].min) != 0) {
                printf("ERROR: type \"%s\" - min != 0\n", names[j]);
                ++result;
            }
        }
    }
    if (result != 0) {
        printf("bounds test - FAILED\n");
        ret = 1;
        result = 0;
    } else {
        printf("bounds test - PASSED\n");
    }
    printf("start bitwidth test\n");
    for (size_t h = 0; h < 8; ++h) {
        if (types[h].bits < BITWIDTH_MIN || types[h].bits > BITWIDTH_MAX) {
            printf("ERROR: type \"%s\" - bitwidth %.0f is unplausible\n", names[h], types[h].bits);
            ++result;
            continue;
        }
        double width = (types[h].min * -1.0) + (types[h].max + 1.0);
        // double bitwidth = log2(types[h].min * -1.0) + (types[h].max + 1.0);
        if ((int)log2(width) != (int)types[h].bits) {
            printf("ERROR: type \"%s\" - distance between min and max of %.0f does not match provided bitwidth of %.0f and should be %d\n", names[h], width, types[h].bits, (int)log2(width));
            ++result;
        }
    }
    if (result != 0) {
        printf("bitwidth test - FAILED\n");
        ret = 1;
        result = 0;
    } else {
        printf("bitwidth test - PASSED\n");
    }
    printf("start standard compliance test\n");
    if (types[0].bits != 8) {  // signed chart == 8 bits
        ++result;
        printf("ERROR: type \"%s\" - bitwidth should be 8\n", names[0]);
    }
    if (types[1].bits != 8) {  // unsigned chart == 8 bits
        ++result;
        printf("ERROR: type \"%s\" - bitwidth should be 8\n", names[1]);
    }
    if (types[2].bits < 16) {  // signed short > 16 bits
        ++result;
        printf("ERROR: type \"%s\" - bitwidth should be more or equal 16\n", names[2]);
    }
    if (types[3].bits < 16) {  // unsigned short > 16 bits
        ++result;
        printf("ERROR: type \"%s\" - bitwidth should be more or equal 16\n", names[3]);
    }
    if (types[4].bits < 16) {  // signed int > 16 bits
        ++result;
        printf("ERROR: type \"%s\" - bitwidth should be more or equal 16\n", names[4]);
    }
    if (types[5].bits < 16) {  // unsigned int > 16 bits
        printf("ERROR: type \"%s\" - bitwidth should be more or equal 16\n", names[5]);
        ++result;
    }
    if (types[6].bits < 32) {  // signed long > 16 bits
        printf("ERROR: type \"%s\" - bitwidth should be more or equal 32\n", names[6]);
        ++result;
    }
    if (types[7].bits < 32) {  // signed long > 16 bits
        printf("ERROR: type \"%s\" - bitwidth should be more or equal 32\n", names[7]);
        ++result;
    }
    if (types[0].bits != types[1].bits) {  // signed chart == 8 bits
        ++result;
        printf("ERROR: type \"%s\" and type \"%s\" bitwidth should be equal\n", names[0], names[1]);
    }
    if (types[2].bits != types[3].bits) {  // signed chart == 8 bits
        ++result;
        printf("ERROR: type \"%s\" and type \"%s\" bitwidth should be equal\n", names[2], names[3]);
    }
    if (types[4].bits != types[5].bits) {  // signed chart == 8 bits
        ++result;
        printf("ERROR: type \"%s\" and type \"%s\" bitwidth should be equal\n", names[4], names[5]);
    }
    if (types[6].bits != types[7].bits) {  // signed chart == 8 bits
        ++result;
        printf("ERROR: type \"%s\" and type \"%s\" bitwidth should be equal\n", names[6], names[7]);
    }

    if (types[2].bits > types[4].bits) {
        ++result;
        printf("ERROR: type \"%s\" must not be larger than type \"%s\"\n", names[2], names[4]);
    }
    if (types[4].bits > types[6].bits) {
        ++result;
        printf("ERROR: type \"%s\" must not be larger than type \"%s\"\n", names[4], names[6]);
    }

    if (types[3].bits > types[5].bits) {
        ++result;
        printf("ERROR: type \"%s\" must not be larger than type \"%s\"\n", names[3], names[5]);
    }
    if (types[5].bits > types[7].bits) {
        ++result;
        printf("ERROR: type \"%s\" must not be larger than type \"%s\"\n", names[5], names[7]);
    }

    if (result != 0) {
        printf("standard compliance test - FAILED\n");
        ret = 1;
        result = 0;
    } else {
        printf("standard compliance test - PASSED\n");
    }
    return ret;
}