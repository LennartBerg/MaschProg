#include <stdio.h>
/*
Implementieren Sie eine main-Funktion, die alle übergebenen argv-Parameter ausgibt
    und die Anzahl der Parameter aus der main-Funktion zurückgibt.
*/

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return argc;
}
