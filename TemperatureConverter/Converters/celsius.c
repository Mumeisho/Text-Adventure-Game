#include <stdio.h>
#include "getTemperatureInput.h"

double convertFromCelsiusToFarenheit(double temperatureInCelsius) {
  double result = temperatureInCelsius * 9.0 / 5.0 + 32.0;
  return result;
}

double convertFromCelsiusToKelvin(double temperatureInCelsius) {
  double result = temperatureInCelsius + 273.15;
  return result;
}

void convertCelsiusValues(char toInput) {
  double result;
  double input = getTemperatureInput();
  switch (toInput) {
    case 'F':
      result = convertFromCelsiusToFarenheit(input);
      printf("%.2f Celsius equals %.2f Farenheit.\n", input, result);
      break;
    case 'K':
      result = convertFromCelsiusToKelvin(input);
      printf("%.2f Celsius equals %.2f Kelvin.\n", input, result);
      break;
    default:
      printf("How did you even get here?\n");
      break;
  }
}