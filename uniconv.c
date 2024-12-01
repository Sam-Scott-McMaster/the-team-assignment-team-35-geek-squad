/* Naqeeb Ahmadzai, Arian Fallahpour-Sichani, Soham Hajariwala, Krish Haryani
*  Ahmadzan, fallahpa, hajariws, 
*  /12/03/2024/
*
* The app will ask the user to enter data in one unit, say Celsius for temperature or meters 
* for distance, and indicate the unit or the quantity they want to convert to, say Fahrenheit 
* or Kilometers. Furthermore, as far as error-handling is concerned, the app will continue to 
* ask the user to input valid numbers if valid numbers are not inputted, ensuring that there are no errors.
*
* This file in particular will handle the main execution logic for the unit conversion program.
*/

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
   error_same_units();
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