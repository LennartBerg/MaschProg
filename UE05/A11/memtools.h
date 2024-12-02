#include <stddef.h>
#include <stdio.h>

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

/*
    returns 0 if the executing machine uses big endian byte order
    returns 1 if the executing machine used little endian byte order
*/
int isLittleEndian();

/*
    enlarges a memory of width of typesize_src to a width of typesize_dest
    copies in src stored values to the wider memory at dest
    takes the sign into account, if sign is provided with 1
    works with little endian byte order, if le is provided with 1

    returns 1, if typesize_src >= typesize_dest
    returns 0, else
*/
int broaden(void* src, void* dest, size_t typesize_src,
            size_t typesize_dest, int sign, int le);

/*
    converts a piece memory from little endian byte order to big endian byte order
    reads at src and writes at dest
    reads and writes typesize bytes
*/
void convertLEtoBE(void* src, void* dest, size_t typesize);

/*
    converts a piece memory from big endian byte order to little endian byte order
    reads at src and writes at dest
    reads and writes typesize bytes
*/
void convertBEtoLE(void* src, void* dest, size_t typesize);