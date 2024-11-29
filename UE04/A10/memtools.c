#include "memtools.h"

// Die reguläre swap Implementierung ist bei mir schneller. Ich vermute,
// weil es auf Maschinencode-Ebene besser optimiert werden kann.
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// void swap(int* a, int* b) {
//     *a ^= *b;
//     *b ^= *a;
//     *a ^= *b;
// }

// Quicksort Implementierung mit Summierung aller Elemente
int quicksort(int* array, int left, int right) {
    // Abbruchkriterium: Kein Teilarray mehr vorhanden.
    if (left > right) {
        return 0;
    }
    // Abbruchkriterium: Teilarray hat Länge 1
    if (left == right) {
        return array[right];
    }
    int i = left;
    int j = right - 1;
    int p = array[right];
    int sum = 0;
    // Sortierung des Arrays anhand des Pivotelements p
    while (i < j) {
        while (i < j && array[i] <= p) {
            i++;
        }
        while (j > i && array[j] > p) {
            j--;
        }
        if (array[i] > array[j]) {
            swap(array + i, array + j);
        }
    }
    if (array[i] > p) {
        swap(array + i, array + right);
    } else {
        i = right;
    }
    // Addition des Pivotelements auf die Summe
    sum += array[i];
    // Sortierung & Summierung linkes Teilarray
    sum += quicksort(array, left, i - 1);
    // Sortierung & Summierung rechts Teilarray
    sum += quicksort(array, i + 1, right);
    return sum;
}

int integersort(int array[], size_t size) {
    return quicksort(array, 0, size - 1);
}

size_t memreverse(void* src, void* dest, size_t typesize, size_t size) {
    // Zeige auf das erste Byte des ersten Elements des Source Arrays
    unsigned char* src_p = (unsigned char*)src;
    // Zeige auf das erste Byte des ersten Elements des Ziel Arrays
    unsigned char* dest_p = (unsigned char*)dest + (size - 1) * typesize;

    // Iteration über alle Elemente
    for (int i = 0; i < size; i++) {
        // Iteration über die Bytes eines Elements
        for (int t = 0; t < typesize; t++) {
            // Kopie des Byte
            *(dest_p + t) = *(src_p + t);
        }
        src_p += typesize;   // Verschiebe Zeiger ein Element weiter
        dest_p -= typesize;  // Verschiebe Zeige ein Element zurück
    }
    return size * typesize;
}