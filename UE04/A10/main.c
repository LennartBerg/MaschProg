#include "sample.h"
#include "sensor_mock.h"

#include <stdio.h>

#define BUFSIZE 8196

int main(void) {
    sensor_mock_t sensor;
    init(&sensor);
    sample_t sample;
    size_t sample_id = 0;
    sample.size = 0;

    //setAfMean(&sample);
    setAfMed(&sample);
    //setAfMin(&sample);
    //setAfMax(&sample);

    char buffer[BUFSIZE];
    char* bIdx = buffer;

    int val = 0;
    while(available(&sensor)) {
        val = read(&sensor);
        if (add(val, &sample)) {
            bIdx += sprintf(
                bIdx, "sample %lu : %d\n",
                sample_id++, aggregate(&sample)
            );
            sample.size = 0;
            add(val, &sample);
        }
    }

    puts(buffer);
    return 0;
}
