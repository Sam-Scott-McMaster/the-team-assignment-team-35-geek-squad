#include "uniconv.h"

int main(int argc, char *argv[]) {
  char type;                           // value from -t
  char input[INPUT_MAX_LENGTH];        // value and input from -i
  char output_unit[UNITS_MAX_LENGTH];  // value from -o

  // Retrieves type, input and output_unit from command
  read_input(argc, argv, &type, input, output_unit);

  printf("%c %s %s\n", type, input, output_unit);

  int input_value;                    // value from -i
  char input_unit[UNITS_MAX_LENGTH];  // unit from -i

  // Retrieves input_value and input_unit from input
  // extract_input(input, input_value, input_unit);

  print_usage();
}