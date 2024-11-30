#include "uniconv.h"

void print_output(double converted_value, char* output_unit) {
  printf("%le", converted_value);

  if (OPTION_REMOVE_UNIT == FALSE) {
    printf("%s", output_unit);
  }

  printf("\n");
}