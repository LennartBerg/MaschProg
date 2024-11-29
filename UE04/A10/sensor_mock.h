#include <stddef.h>
#include <math.h>

#define SENSOR_DATA_LEN 2048
#define SENSOR_FACTOR 1000.0
#define SENSOR_OFFSET 150.0

typedef struct {
    int data[SENSOR_DATA_LEN];
    size_t idx;
} sensor_mock_t;

void init(sensor_mock_t* sensor) {
    sensor->idx = 0;
    for (size_t i = 0; i < SENSOR_DATA_LEN; ++i) {
        sensor->data[i] = (int)(sin(i) * SENSOR_FACTOR) + SENSOR_OFFSET;
    }
}

int available(sensor_mock_t* sensor) {
    return (sensor->idx < SENSOR_DATA_LEN);
}

int read(sensor_mock_t* sensor) {
    return sensor->data[sensor->idx++];
}