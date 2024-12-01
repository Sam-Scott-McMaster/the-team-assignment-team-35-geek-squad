/* Naqeeb Ahmadzai, Arian Fallahpour-Sichani, Soham Hajariwala, Krish Haryani
*  Ahmadzan, fallahpa, hajariws, 
*  /12/03/2024/
*
* The app will ask the user to enter data in one unit, say Celsius for temperature or meters 
* for distance, and indicate the unit or the quantity they want to convert to, say Fahrenheit 
* or Kilometers. Furthermore, as far as error-handling is concerned, the app will continue to 
* ask the user to input valid numbers if valid numbers are not inputted, ensuring that there are no errors.
*
* This file in particular will do the error handling.
*/

#include "uniconv.h"


// Handles invalid types.
void error_invalid_type() {
    fprintf(stderr, "Error: The conversion type provided is invalid.\n");
    exit(EXIT_FAILURE);
}


// Handles invalid unit error.
void error_invalid_unit() {
    fprintf(stderr, "Error: Please check input as an invalid unit was provided.\n");
    exit(EXIT_FAILURE);
}


// Handles negative mass.
void error_negative_mass() {
    fprintf(stderr, "Error: Mass cannot be negative, please input an valid mass.");
    exit(EXIT_FAILURE);
    }

// Handles missing required arugments.
void error_missing_args() {
    fprintf(stderr, "Error: Missing required argumetns. Please use --help for usage instrucitons.\n");
    exit(EXIT_FAILIRE);
}


// Handles same input and output units.
void error_same_units(){
    fprintf(stderr, "Error: The input and output are both the same units, please use different ones.\n");
    exit(EXIT_FAILURE);
}