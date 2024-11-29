#include "sample.h"

#include "memtools.h"

int mean(int* data, size_t size) {
    long int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

void setAfMean(sample_t* sam) {
    sam->f_aggr = mean;
    return;
}

int med(int* data, size_t size) {
    integersort(data, size);
    if (size % 2 == 1) {
        return data[size / 2];
    }
    return (data[size / 2] + data[size / 2 + 1]) / 2;
}

void setAfMed(sample_t* sam) {
    sam->f_aggr = med;
    return;
}

int min(int* data, size_t size) {
    int min = data[0];
    for (int i = 1; i < size; i++) {
        if (min > data[i]) {
            min = data[i];
        }
    }
    return min;
}

void setAfMin(sample_t* sam) {
    sam->f_aggr = min;
    return;
}

int max(int* data, size_t size) {
    int max = data[0];
    for (int i = 1; i < size; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }
    return max;
}

void setAfMax(sample_t* sam) {
    sam->f_aggr = max;
    return;
}

int aggregate(sample_t* sam) {
    return sam->f_aggr(sam->data, sam->size);
}

int add(int val, sample_t* sam) {
    if (sam->size < SAMPLE_DATA_LEN) {
        sam->data[sam->size++] = val;
        return 0;
    }
    return 1;
}