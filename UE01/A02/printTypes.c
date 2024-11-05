#include "printTypes.h"

#include <limits.h>
#include <stdio.h>

void printTypesToJson(char* buffer) {
    sprintf(buffer,
            "{\n\
    \"signed char\":{\n\
        \"Min\":-128,\n\
        \"Max\":127,\n\
        \"Bits\":8\n\
    },\n\
    \"unsigned char\":{\n\
        \"Min\":0,\n\
        \"Max\":255,\n\
        \"Bits\":8\n\
    },\n\
    \"signed short\":{\n\
        \"Min\":-32768,\n\
        \"Max\":32767,\n\
        \"Bits\":16\n\
    },\n\
    \"unsigned short\":{\n\
        \"Min\":0,\n\
        \"Max\":65535,\n\
        \"Bits\":16\n\
    },\n\
    \"signed int\":{\n\
        \"Min\":-32768,\n\
        \"Max\":32767,\n\
        \"Bits\":16\n\
    },\n\
    \"unsigned int\":{\n\
        \"Min\":0,\n\
        \"Max\":65535,\n\
        \"Bits\":16\n\
    },\n\
    \"signed long\":{\n\
        \"Min\":-2147483648,\n\
        \"Max\":2147483647,\n\
        \"Bits\":32\n\
    },\n\
    \"unsigned long\":{\n\
        \"Min\":0,\n\
        \"Max\":4294967295,\n\
        \"Bits\":32\n\
    }\n\
}");
}