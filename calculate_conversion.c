/* Naqeeb Ahmadzai, Arian Fallahpour-Sichani, Soham Hajariwala, Krish Haryani
 *  Ahmadzan, fallahpa, hajariws,
 *  /12/03/2024/
 *
 * The app will ask the user to enter data in one unit, say Celsius for
 * temperature or meters for distance, and indicate the unit or the quantity
 * they want to convert to, say Fahrenheit or Kilometers. Furthermore, as far as
 * error-handling is concerned, the app will continue to ask the user to input
 * valid numbers if valid numbers are not inputted, ensuring that there are no
 * errors.
 *
 * This file in particular will handle the logic for performing the actual unit
 * conversions..
 */

#include "uniconv.h"

typedef struct {
  char name[UNITS_MAX_LENGTH];
  double value;
} factor;

// BASE: meters
factor distances_metric[] = {
    {"Tm", 1E12}, {"Gm", 1E9},  {"Mm", 1E6},   {"km", 1E3},  {"hm", 1E2},
    {"dam", 1E1}, {"m", 1.0},   {"dm", 1E-1},  {"cm", 1E-2}, {"mm", 1E-3},
    {"um", 1E-6}, {"nm", 1E-9}, {"pm", 1E-12},
};

// In terms of meters
factor distances_imperial[] = {
    {"mi", 1609.3445},
    {"yd", 0.91440276},
    {"in", 0.025399986},
    {"ft", 0.30479999},
};

// BASE: gram
factor mass_metric[] = {
    {"Tg", 1E12}, {"Gg", 1E9},  {"Mg", 1E6},   {"kg", 1E3},  {"hg", 1E2},
    {"dag", 1E1}, {"g", 1.0},   {"dg", 1E-1},  {"cg", 1E-2}, {"mg", 1E-3},
    {"ug", 1E-6}, {"ng", 1E-9}, {"pg", 1E-12},
};

// In terms of grams
factor mass_imperial[] = {
    {"t", 907185.81887128},
    {"st", 6350.2949712},
    {"lb", 453.59290944},
    {"oz", 28.34949254},
};

double calculate_conversion(char type, char* input_unit, double input_value,
                            char* output_unit) {
  // Temperature calculation
  if (type == 't' || type == 'T') {
    return convert_temperature(input_unit, input_value, output_unit);
  }

  // Distance calculation
  else if (type == 'd' || type == 'D') {
    double multiplier =
        get_distance_factor(input_unit) / get_distance_factor(output_unit);
    return input_value * multiplier;
  }

  // Area calculation
  else if (type == 'a' || type == 'A') {
    double multiplier = pow(
        get_distance_factor(input_unit) / get_distance_factor(output_unit), 2);
    return input_value * multiplier;
  }

  // Area calculation
  else if (type == 'v' || type == 'V') {
    double multiplier = pow(
        get_distance_factor(input_unit) / get_distance_factor(output_unit), 3);
    return input_value * multiplier;
  }

  // Mass calculation
  else if (type == 'm' || type == 'M') {
    if (input_value <= 0) {
      error_negative_mass();
      exit(EXIT_FAILURE);
    }

    double multiplier =
        get_mass_factor(input_unit) / get_mass_factor(output_unit);
    return input_value * multiplier;
  } else {
    error_invalid_type();
    exit(EXIT_FAILURE);
  }
}

double get_distance_factor(char* unit) {
  for (int i = 0; i < sizeof(distances_metric) / sizeof(factor); i++) {
    if (strcmp(distances_metric[i].name, unit) == TRUE) {
      return distances_metric[i].value;
    }
  }

  for (int i = 0; i < sizeof(distances_imperial) / sizeof(factor); i++) {
    if (strcmp(distances_imperial[i].name, unit) == TRUE) {
      return distances_imperial[i].value;
    }
  }
  error_invalid_unit();
  exit(EXIT_FAILURE);
}

double get_mass_factor(char* unit) {
  for (int i = 0; i < sizeof(mass_metric) / sizeof(factor); i++) {
    if (strcmp(mass_metric[i].name, unit) == TRUE) {
      return mass_metric[i].value;
    }
  }

  for (int i = 0; i < sizeof(mass_imperial) / sizeof(factor); i++) {
    if (strcmp(mass_imperial[i].name, unit) == TRUE) {
      return mass_imperial[i].value;
    }
  }
  error_invalid_unit();
  exit(EXIT_FAILURE);
}

double convert_temperature(char* input_unit, double input_value,
                           char* output_unit) {
  double intermediate;  // intermediate value in celsius

  // Convert to an intermediate celsius value
  if (strcmp(input_unit, "f") == TRUE) {
    intermediate = (input_value - 32.0) * (5.0 / 9.0);
  } else if (strcmp(input_unit, "K") == TRUE) {
    intermediate = input_value + (KELVIN_ADJUSTMENT);
  } else if (strcmp(input_unit, "C") == TRUE) {
    intermediate = input_value;
  } else {
    error_invalid_unit();
    exit(EXIT_FAILURE);
  }

  if (intermediate < KELVIN_ADJUSTMENT) {
    error_invalid_temperature(intermediate);
    exit(EXIT_FAILURE);
  }

  // Return in terms of output unit
  if (strcmp(output_unit, "f") == TRUE) {
    return intermediate * (9.0 / 5.0) + 32.0;
  } else if (strcmp(output_unit, "K") == TRUE) {
    return intermediate + 273.15;
  } else if (strcmp(output_unit, "C") == TRUE) {
    return intermediate;
  } else {
    error_invalid_unit();
    exit(EXIT_FAILURE);
  }
}
