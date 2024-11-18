#include <stddef.h>

/*
    sorts all values of an integer array in acending order

    array: address an integer array of
    size: elements

    returns the sum of elements as checksum
*/

int integersort(int array[], size_t size);


/* 
    copies reversely a given memory at src into dest and converts the sequence into an inverse order

    src: address of the source memory
    dest: address of the destinations memory
    typesize: size of elements
    size: number of elements to copy, both memories must be of sufficient size

    returns the number of bytes written
 */
size_t memreverse(void* src, void* dest, size_t typesize, size_t size);