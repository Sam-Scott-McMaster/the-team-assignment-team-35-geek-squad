#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS_MAX_LENGTH 4
#define VALUE_MAX_LENGTH 13
#define INPUT_MAX_LENGTH UNITS_MAX_LENGTH + VALUE_MAX_LENGTH

void print_usage();
void print_help();
void read_input(char *type, char input[], char output_unit[]);