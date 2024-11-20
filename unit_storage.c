#include "uniconv.h"
#include <stdio.h>
#include <string.h>
#define METRIC_IMPERIAL 0.0254
typedef struct {
    char name[10];
    char value[20];
} prefix;

prefix metric[12] = {
    {"T", "1000000000000"},
    {"G", "1000000000"},
    {"M", "1000000"},
    {"k", "1000"},
    {"h", "100"},
    {"da", "10"},
    {"d", "0.1"},
    {"c", "0.01"},
    {"m", "0.001"},
    {"u", "0.000001"},
    {"n", "0.000000001"},
    {"p", "0.000000000001"},
};
prefix imperial[4] = {
    {"m", "63360"},
    {"yd", "36"},
    {"ft", "12"},
    {"in", "1"},
};
char* getValue(prefix* array, int size, char* name) {
    for(int i = 0; i < size; i++) {
        if (strcmp(array[i].name, name) == 0) {
            return array[i].value;
        }
    }
    return NULL;
}
int main() {
    char* result = getValue(metric, 12, "k");
    if (result != NULL) {
        printf("Value for 'k' in metric: %s\n", result);
    } else {
        printf("Prefix not found in metric.\n");
    }
}
