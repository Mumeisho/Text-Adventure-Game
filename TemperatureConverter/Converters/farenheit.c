#include <stdio.h>
#include "getTemperatureInput.h"

double convertFromFarenheitToCelsius(double temperatureInFarenheit) {
  double result = (temperatureInFarenheit - 32.0) * (5.0 / 9.0);
  return result;
}

double convertFromFarenheitToKelvin(double temperatureInFarenheit) {
  double result = convertFromFarenheitToCelsius(temperatureInFarenheit) + 273.15;
  return result;
}

void convertFarenheitValues(char toInput) {
  double result;
  double input = getTemperatureInput();
  switch (toInput) {
    case 'C':
      result = convertFromFarenheitToCelsius(input);
      printf("%.2f Farenheit equals %.2f Celsius.\n", input, result);
      break;
    case 'K':
      result = convertFromFarenheitToKelvin(input);
      printf("%.2f Farenheit equals %.2f Kelvin.\n", input, result);
      break;
    default:
      printf("How did you even get here?\n");
      break;
  }
}