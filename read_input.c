#include "uniconv.h"

void read_input(int argc, char *argv[], char *type,
                char input[INPUT_MAX_LENGTH],
                char output_unit[UNITS_MAX_LENGTH]) {
  if (argc <= 1) {
    fprintf(stderr, "PLEASE PROVIDE INPUTS");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    // Type argument
    if (strcmp(argv[i], "-t") == 0) {
      strcpy(type, argv[i + 1]);
    }

    // Input argument
    else if (strcmp(argv[i], "-i") == 0) {
      strcpy(input, argv[i + 1]);

    }

    // Output unit argument
    else if (strcmp(argv[i], "-o") == 0) {
      strcpy(output_unit, argv[i + 1]);
    }

    i++;
  }
}
