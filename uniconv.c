#include "uniconv.h"

int OPTION_REMOVE_UNIT = FALSE;

int main(int argc, char *argv[]) {
  char type;                           // value from -t
  double input_value;                  // numerical value from -i
  char input_unit[UNITS_MAX_LENGTH];   // unit from -i
  char output_unit[UNITS_MAX_LENGTH];  // value from -o

  // Retrieve unit type, input value, input unit and output unit from args
  read_input(argc, argv, &type, &input_value, input_unit, output_unit);

  // If input value not provided, continuously read input value
  if (PROVIDED_INPUT_VALUE == FALSE) {
    while (scanf("%lf", &input_value) != EOF) {
      // HANDLE ERROR: Check if value is greater than 0
      if (input_value <= 0) {
        fprintf(stderr, "Input value must be greater than 0.\n");
        exit(EXIT_FAILURE);
      }

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