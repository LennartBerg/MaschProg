#include <stddef.h>
#define SAMPLE_DATA_LEN 256

/*
    Stores a row of data, a counter
    and a function pointer to process the data
*/
typedef struct {
    int data[SAMPLE_DATA_LEN];
    size_t size;
    int (*f_aggr)(int*, size_t);
} sample_t;

/*
    Standard functions to aggregate data.
    First parameter is a pointer on a int-row to process.
    Second parameter is the length of the row to process.

    Returns a value, which is the aggregate
    of the processed data.
*/
int mean(int*, size_t);
int med(int*, size_t);
int min(int*, size_t);
int max(int*, size_t);

/*
    Executes the aggregate function of a provided sample.
    Returns the value of the aggregate function.
*/
int aggregate(sample_t*);

/*
    Adds a value to the sample.
    Returns 0 if succeeded.
*/
int add(int, sample_t*);

/*
    These functions set a aggregate function
    to a as parameter provided sample.
    Returns nothing.
*/
void setAfMean(sample_t*);
void setAfMed(sample_t*);
void setAfMin(sample_t*);
void setAfMax(sample_t*);