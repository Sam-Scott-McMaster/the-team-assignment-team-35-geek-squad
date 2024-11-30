#include "uniconv.h"

int PROVIDED_INPUT_TYPE = FALSE;
int PROVIDED_INPUT_VALUE = FALSE;
int PROVIDED_INPUT_UNIT = FALSE;
int PROVIDED_OUTPUT_UNIT = FALSE;

void read_input(int argc, char *argv[], char *type, double *input_value,
                char input_unit[UNITS_MAX_LENGTH],
                char output_unit[UNITS_MAX_LENGTH]) {
  // Loops through all options
  for (int i = 1; i < argc; i++) {
    // Type argument
    if (strcmp(argv[i], "-t") == TRUE) {
      strcpy(type, argv[i + 1]);
      PROVIDED_INPUT_TYPE = TRUE;
    }

    // Input value argument
    else if (strcmp(argv[i], "-iv") == TRUE) {
      int result = sscanf(argv[i + 1], "%lf", input_value);
      if (result == 1) {
        // HANDLE ERROR: Check if value is greater than 0
        if (*input_value <= 0) {
          fprintf(stderr, "Input value must be greater than 0.\n");
          exit(EXIT_FAILURE);
        }
        PROVIDED_INPUT_VALUE = TRUE;
      }

    }

    // Input value argument
    else if (strcmp(argv[i], "-iu") == TRUE) {
      int result = sscanf(argv[i + 1], "%s", input_unit);

      // HANDLE ERROR: Check if unit was provided
      if (result == 1) {
        PROVIDED_INPUT_UNIT = TRUE;
      } else {
        fprintf(stderr, "Invalid input format.\n");
        exit(EXIT_FAILURE);
      }

    }

    // Output unit argument
    else if (strcmp(argv[i], "-o") == TRUE) {
      strcpy(output_unit, argv[i + 1]);
      PROVIDED_OUTPUT_UNIT = TRUE;
    }

    // Options
    else if (strcmp(argv[i], "-ru") == TRUE) {
      OPTION_REMOVE_UNIT = TRUE;
    }

    // HELP
    else if (strcmp(argv[i], "--help") == TRUE) {
      print_help();
      exit(EXIT_SUCCESS);
    }

    i++;
  }

  // HANDLE ERROR: check if all required inputs have been provided
  if (PROVIDED_INPUT_TYPE == FALSE || PROVIDED_INPUT_UNIT == FALSE ||
      PROVIDED_OUTPUT_UNIT == FALSE) {
    print_usage();
    exit(EXIT_FAILURE);
  }
}
