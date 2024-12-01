/* Naqeeb Ahmadzai, Arian Fallahpour-Sichani, Soham Hajariwala, Krish Haryani
*  Ahmadzan, fallahpa, hajariws, 
*  /12/03/2024/
*
* The app will ask the user to enter data in one unit, say Celsius for temperature or meters 
* for distance, and indicate the unit or the quantity they want to convert to, say Fahrenheit 
* or Kilometers. Furthermore, as far as error-handling is concerned, the app will continue to 
* ask the user to input valid numbers if valid numbers are not inputted, ensuring that there are no errors.
*
* This file in particular will define constants, function prototypes, and global variables for the program.
*/


#include <math.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS_MAX_LENGTH 3
#define VALUE_MAX_LENGTH 13
#define INPUT_MAX_LENGTH UNITS_MAX_LENGTH + VALUE_MAX_LENGTH

#define KELVIN_ADJUSTMENT -273.15

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

void error_invalid_type();
void error_invalid_unit();
void error_negative_mass();
void error_missing_args();
void error_same_units();