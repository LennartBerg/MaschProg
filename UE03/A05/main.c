#include <stdio.h>
#include "memtools.h"
/*
A) Implementieren Sie die Funktion "integersort" in der Datei "memtools.c".
    Halten Sie sich dabei an die Funktionsbeschreibung in der Header-Datei "memtools.h".
    
    Die Funktion erhält ein Integer-Array, sowie dessen Länge.
    Sortieren Sie die enthaltenen Elemente. Hierfür bietet sich der Bubble-Sort-Algorithmus an.
    
    Tipp: Da die übergebene Array-Adresse typisiert ist, können Sie sowohl Pointerarithmetik,
        alsauch die bekannten Array-Zugriffsoperatoren nutzen.
        Ein XOR-Swap macht eine zusätzliche Variable überflüssig.
    
B) Implementieren Sie die Funktion "memreverse" in der Datei "memtools.c".
    Halten Sie sich dabei an die Funktionsbeschreibung in der Header-Datei "memtools.h".

    Die Funktion nimmt einen Pointer beliebigen Typs auf ein Array entgegen,
        ließt die hinterlegten Werte und schreibt diese in ein weiteres Array beliebigen Typs.
    Dabei invertiert sie die Indices gegenüber den Quellarray und invertiert somit die
        Reihenfolge der Elemente im Zielarray.
    

    Tipp: Arbeiten Sie auf Byte-Ebene.
        Dies ist notwendig, da der Typ des übergebenen Arrays innerhalb der Funktion memreverse
            nicht bekannt sind.
        Konvertieren Sie die übergebenen Pointer zunächst zu Pointern, die auf ein einzelnes Byte zeigen.
*/

#define LEN 10

int main(void) {
    int sequenz[] = {0,100,200,300,-4000,50000,-600000,7000000,-80000000,900000000};
    printf("source: [%d",sequenz[0]);
    for (size_t i = 1; i < LEN; ++i) 
        printf(",%d", sequenz[i]);
    printf("]\n");
    
    int chs = integersort(sequenz, LEN);

    int result[LEN];

    size_t ret = memreverse(sequenz, result, sizeof(int), LEN);

    printf("sorted: [%d",sequenz[0]);
    for (size_t i = 1; i < LEN; ++i) 
        printf(",%d", sequenz[i]);
    printf("] /%d\ndest:   [%d", chs, result[0]);
    for (size_t i = 1; i < LEN; ++i) 
        printf(",%d", result[i]);
    printf("]\nCopied %u byte\n",ret);

    return 0;
}