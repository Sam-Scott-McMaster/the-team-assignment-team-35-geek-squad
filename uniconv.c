#include "uniconv.h"

int OPTION_REMOVE_UNIT = FALSE;

int main(int argc, char *argv[]) {
  char type;                           // value from -t
  double input_value;                  // numerical value from -i
  char input_unit[UNITS_MAX_LENGTH];   // unit from -i
  char output_unit[UNITS_MAX_LENGTH];  // value from -o

  // Retrieve unit type, input value, input unit and output unit from args
  read_input(argc, argv, &type, &input_value, input_unit, output_unit);

  // HANDLE ERROR: Check if input and output are not the same
  if (strcmp(input_unit, output_unit) == 0) {
    fprintf(stderr, "Input and output units must be different.\n");
    exit(EXIT_FAILURE);
  }

  // If input value not provided, continuously read input value
  if (PROVIDED_INPUT_VALUE == FALSE) {
    while (scanf("%lf", &input_value) != EOF) {
      // Convert the input value in terms of the output value's units
      double converted =
          calculate_conversion(type, input_unit, input_value, output_unit);

      // Print converted value
      print_output(converted, output_unit);
    }
  } else {
    // Convert the input value in terms of the output value's units
    double converted =
        calculate_conversion(type, input_unit, input_value, output_unit);

    // Print converted value
    print_output(converted, output_unit);
  }
}