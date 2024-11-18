#include "uniconv.h"

int main(int argc, char *argv[]) {
  char type;                           // value from -t
  double input_value;                  // value from -i
  char input_unit[UNITS_MAX_LENGTH];   // unit from -i
  char output_unit[UNITS_MAX_LENGTH];  // value from -o

  // Retrieves type, input and output_unit from command
  read_input(argc, argv, &type, &input_value, input_unit, output_unit);

  printf("%c %lf %s %s\n", type, input_value, input_unit, output_unit);

  print_usage();
}