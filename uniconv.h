#include <math.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS_MAX_LENGTH 3
#define VALUE_MAX_LENGTH 13
#define INPUT_MAX_LENGTH UNITS_MAX_LENGTH + VALUE_MAX_LENGTH
#define TRUE 0
#define FALSE 1

extern int OPTION_REMOVE_UNIT;

extern int PROVIDED_INPUT_TYPE;
extern int PROVIDED_INPUT_VALUE;
extern int PROVIDED_INPUT_UNIT;
extern int PROVIDED_OUTPUT_UNIT;

void print_usage();
void print_help();
void read_input(int argc, char* argv[], char* type, double* input_value,
                char input_unit[UNITS_MAX_LENGTH],
                char output_unit[UNITS_MAX_LENGTH]);

double calculate_conversion(char type, char* input_unit, double input_value,
                            char* output_unit);
double get_distance_factor(char* unit);
double get_mass_factor(char* unit);
double convert_temperature(char* input_unit, double input_value,
                           char* output_unit);

void print_output(double converted_value, char* output_unit);