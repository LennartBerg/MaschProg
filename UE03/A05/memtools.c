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

void quicksort(int* array, int left, int right) {
    int i = left;
    int j = right - 1;
    int p = array[right];
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
    if (left < i - 1) {
        quicksort(array, left, i - 1);
    }
    if (i + 1 < right) {
        quicksort(array, i + 1, right);
    }
}

int integersort(int array[], size_t size) {
    quicksort(array, 0, size - 1);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

size_t memreverse(void* src, void* dest, size_t typesize, size_t size) {
    // Zeige auf das erste Element des Source Arrays
    unsigned char* src_p = (unsigned char*)src;
    // Zeige auf das letzte Element des Ziel Arrays
    unsigned char* dest_p = (unsigned char*)dest + (size - 1) * typesize;

    // Iteration über alle Elemente
    for (int i = 0; i < size; i++) {
        // Iteration über die Byte-Teile eines Elements
        for (int t = 0; t < typesize; t++) {
            // Kopie des Elements
            *(dest_p + t) = *(src_p + t);
        }
        src_p += typesize; // Verschiebe Zeiger ein Element weiter
        dest_p -= typesize; // Verschiebe Zeige ein Element zurück
    }
    return size * typesize;
}