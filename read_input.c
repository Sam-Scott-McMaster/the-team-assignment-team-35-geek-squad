#include "uniconv.h"

void read_input(int argc, char *argv[], char *type, double *input_value,
                char input_unit[UNITS_MAX_LENGTH],
                char output_unit[UNITS_MAX_LENGTH]) {
  // Check if all inputs have been provided
  if (argc != 7) {
    print_usage();
    exit(EXIT_FAILURE);
  }

  // Loops through all options
  for (int i = 1; i < argc; i++) {
    // Type argument
    if (strcmp(argv[i], "-t") == 0) {
      strcpy(type, argv[i + 1]);

      // TODO: Check if unit type is accepted
    }

    // Input argument
    else if (strcmp(argv[i], "-i") == 0) {
      int result = sscanf(argv[i + 1], "%lf%s", input_value, input_unit);

      // Check if scanned result is valid
      if (result != 2) {
        fprintf(stderr, "Invalid input format.\n");
        exit(EXIT_FAILURE);
      }

      // TODO Check if input value is valid

      // TODO Check if input unit is valid
    }

    // Output unit argument
    else if (strcmp(argv[i], "-o") == 0) {
      strcpy(output_unit, argv[i + 1]);

      // TODO: Check if ouput unit is accepted
    }

    i++;
  }
}
