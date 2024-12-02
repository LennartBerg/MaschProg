#include "memtools.h"

typedef unsigned char byte_t;  // named type to convey intention

int integersort(int array[], size_t size) {
    int ret = 0;

    for (unsigned int i = 1; i < size; ++i) {
        for (unsigned int j = 0; j < size - 1; ++j) {
            if (array[j] > array[j + 1]) {
                array[j] ^= array[j + 1];
                array[j + 1] ^= array[j];
                array[j] ^= array[j + 1];
            }
        }
    }

    for (unsigned int i = 0; i < size; ++i) {
        ret += array[i];
    }

    return ret;
}

size_t memreverse(void* src, void* dest, size_t typesize, size_t size) {
    unsigned char* psrc = src;
    unsigned char* pdest = dest;

    size_t cnter = 0;
    for (size_t idx = 0; idx < size; ++idx) {
        for (unsigned int byte = 0; byte < typesize; ++byte) {
            *(pdest + ((size - 1 - idx) * typesize) + byte) = *(psrc + (idx * typesize) + byte);
            ++cnter;
        }
    }
    return cnter;
}

int isLittleEndian() {
    // use a type with multiple bytes.
    unsigned long data = 1;
    // get a pointer to the 'first' part of the int.
    byte_t* data_p = (byte_t*)&data;
    // if the first part is 1, then it's little endian.
    return *data_p == 1;
}

int broaden(void* src, void* dest, size_t typesize_src,
            size_t typesize_dest, int sign, int le) {
    if (typesize_src >= typesize_dest) {  // check is data fits
        return 1;
    }
    byte_t* src_p = (byte_t*)src;
    byte_t* dest_p = (byte_t*)dest;
    if (le) {
        // little endian is easier, because the bytes are copied from the src
        // to the dest at the same indexes

        // copy src bytes
        for (int i = 0; i < typesize_src; i++) {
            dest_p[i] = src_p[i];
        }
        // fill remaining bytes with zeros
        for (int i = typesize_src; i < typesize_dest; i++) {
            dest_p[i] = 0;
        }
    } else {
        // big endian requires copying the bytes in ascending order from src
        // and writing at descending order in dest

        // copy src bytes
        for (int i = typesize_src, j = 0; i < typesize_dest; i++, j++) {
            dest_p[i] = src_p[j];
        }
        // fill remaining bytes with zeros
        for (int i = 0; i < typesize_src; i++) {
            dest_p[i] = 0;
        }
    }
    return 0;
}

// LE to BE is essentially the same as BE to LE, because the bytes just get
// reversed both times

void convertLEtoBE(void* src, void* dest, size_t typesize) {
    memreverse(src, dest, 1, typesize);
}

void convertBEtoLE(void* src, void* dest, size_t typesize) {
    memreverse(src, dest, 1, typesize);
}