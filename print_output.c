/* Naqeeb Ahmadzai, Arian Fallahpour-Sichani, Soham Hajariwala, Krish Haryani
*  Ahmadzan, fallahpa, hajariws, 
*  /12/03/2024/
*
* The app will ask the user to enter data in one unit, say Celsius for temperature or meters 
* for distance, and indicate the unit or the quantity they want to convert to, say Fahrenheit 
* or Kilometers. Furthermore, as far as error-handling is concerned, the app will continue to 
* ask the user to input valid numbers if valid numbers are not inputted, ensuring that there are no errors.
*
* This file in particular will handle printing the converted output value to the console.
*/

#include "uniconv.h"

void print_output(double converted_value, char* output_unit) {
  printf("%le", converted_value);

  if (OPTION_REMOVE_UNIT == FALSE) {
    printf("%s", output_unit);
  }

  printf("\n");
}