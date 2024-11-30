#include "uniconv.h"

int main(int argc, char *argv[]) {
  char type;                           // value from -t
  double input_value;                  // numerical value from -i
  char input_unit[UNITS_MAX_LENGTH];   // unit from -i
  char output_unit[UNITS_MAX_LENGTH];  // value from -o

  // Retrieve unit type, input value, input unit and output unit from args
  read_input(argc, argv, &type, &input_value, input_unit, output_unit);

  // TEST: view values
  // printf("%c %le %s %s\n", type, input_value, input_unit, output_unit);

  double converted =
      calculate_conversion(type, input_unit, input_value, output_unit);

  // Print converted value
  printf("%le%s\n", converted, output_unit);
}