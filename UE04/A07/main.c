#include <stdio.h>

#include "svs_atoi.h"
/*
    Implementieren Sie eine main-Funktion, die drei Aufrufparameter der Form "1 + 1" annimmt.
    Dabei soll die Funktion eines Rechners für die Operationen +,-,*,/ realisiert werden.
    Überprüfen Sie das Aufrufformat.
    Ihnen hilft die svs_atoi-Bibliothek.
    Können die übergebenen Parameter verarbeitet werden, dann return das Programm 0, sonst 1.
*/

int main(int argc, char *argv[]) {
    int left, right;

    if (argc != 4) {
        printf("Wrong number of arguments.");
        return 1;
    }

    if (svs_atoi(argv[1], &left)) {
        printf("Left operand is not a number!");
        return 1;
    }
    if (svs_atoi(argv[3], &right)) {
        printf("Right operand is not a number!");
        return 1;
    }

    switch (argv[2][0]) {
        case '+': {
            printf("%d + %d = %d\n", left, right, left + right);
            break;
        }
        case '-': {
            printf("%d - %d = %d\n", left, right, left - right);
            break;
        }
        case '*': {
            printf("%d * %d = %d\n", left, right, left * right);
            break;
        }
        case '/': {
            printf("%d / %d = %d\n", left, right, left / right);
            break;
        }
        case '%': {
            printf("%d %% %d = %d\n", left, right, left % right);
            break;
        }
        default: {
            printf("Unknown operator!");
            return 1;
        }
    }
    return 0;
}
