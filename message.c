#include "uniconv.h"

void print_usage() {
  fprintf(stderr, "Usage:\n");
  fprintf(stderr, "\n");
  fprintf(stderr,
          "convert [-t t|T|d|D|a|A|v|V|m|M] [-i <number><unit>] [-o <unit>] "
          "[...options]\n\n");
}

void print_help() {
  printf("HELP MENU\n\n");

  printf("OPTIONS\n");
  printf("  -t TYPE             Specify the type of conversions.\n");
  printf("                      t|T: Temprature\n");
  printf("                      d|D: Distance\n");
  printf("                      a|A: Area\n");
  printf("                      v|V: Volume\n");
  printf("                      m/M: Mass\n\n");

  printf(
      "  -iv <double>        Optional value to convert from for the "
      "conversion. \n");
  printf(
      "                      If value not provided, program will continuously "
      "convert numbers from stdin. \n");
  printf("                      Example: 10.00, 31.3, 22.\n\n");

  printf("  -iu <unit>          Unit to convert from for the conversion. \n");
  printf("                      Example: yd, mi, m, mm, kg, f, C.\n\n");

  printf("  -ru                 Remove unit from the output.\n");
  printf(
      "                      Example; 1000m to km results in 1 instead of "
      "1km.\n\n");

  printf("SUPPORTED CONVERSIONS");
  printf("  1. Temperature: Kelvin, Celsius, Fahrenhiet.\n");
  printf("  2. Distance:.\n");
  printf(
      "      - Metric: Terameter, Gigameter, ..., Meter, ..., Millitmeter.\n");
  printf("  3. Area.\n");
  printf("      - Metric: Terameter^2, ..., Millimeter^2.\n");
  printf("      - Imperial: Inch^2, Foot^2, Yard^2, Mile^2.\n");
  printf("  4. Volume:\n");
  printf("      - Metric: Terameter^3, ..., Millimeter^3.\n");
  printf("      - Imperial: Inch^3, Foot^3, Yard^3, Mile^3.\n");
  printf("  5. Mass:\n");
  printf("      - Metric: Teragram, ..., Milligram.\n");
  printf("      - Imperial: Ounce, Pound, Stone.\n\n");

  printf("NOTES\n");
  printf(
      "  - Ensure correct units are used for input and output to avoid "
      "errors.\n");
  printf(
      "  - For invalid inputs or unsupported conversions, the app will prompt "
      "for corrections.\n\n");
}