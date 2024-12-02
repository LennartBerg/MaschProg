#include <stdio.h>
#include "memtools.h"

#define VAL -42

void printMemory(void* src, size_t size) {
    printf("+------------+-----+\n\
|  Address   | Val |\n+------------+-----+\n");
    unsigned char* byte = src;

    for (size_t i = 0; i < size; i++)
    {
        printf("| 0x%.8X | %.3u |\n", byte+i, *(byte+i));
    }
    printf("+------------+-----+\n");
}

int main(void) {
    printf("This machine uses ");
    int is_little = isLittleEndian();
    char s_bo[] = "LE";
    char s_nbo[] = "BE";
    if (is_little) {
        printf("Little");
    } else {
        printf("Big");
        s_bo[0] = 'B';
        s_bo[1] = 'E';
        s_nbo[0] = 'L';
        s_nbo[1] = 'E';
    }
    printf("-Endian byte order\n");

    int a = VAL;
    int b;
    long c;
    long d;

    printf("\n%d int in %s byte order:\n", a, s_bo);
    printMemory(&a, sizeof(a));

    convertLEtoBE(&a, &b, sizeof(a));
    printf("\n%d int in %s byte order:\n", a, s_nbo);
    printMemory(&b, sizeof(b));

    broaden(&a, &c, sizeof(a), sizeof(c), 1, is_little);
    printf("\n%d long in %s byte order:\n", a, s_bo);
    printMemory(&c, sizeof(c));

    broaden(&b, &d, sizeof(b), sizeof(d), 1, !is_little);
    printf("\n%d long in %s byte order:\n", a, s_nbo);
    printMemory(&d, sizeof(d));
    
    return 0;
}