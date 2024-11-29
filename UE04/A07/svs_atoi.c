#include "svs_atoi.h"

int svs_atoi(char str[], int *ret) {
    int result = 0;
    int sign = 1;
    int lng = 0;

//Bestimme Vorzeichen
    if (str[0] == '-') {
        lng = 1;
        sign = -1;
    }

//Bestimme Laenge
    while (str[lng] != '\0') {
        /* Keine Zahl => Abbruch */
        if(str[lng] > '9' || str[lng] < '0') {
            return 1;
        }
        result *= 10;
        result += (str[lng] - '0');
        lng++;
    }

    *ret = result * sign;
    return 0;
}
