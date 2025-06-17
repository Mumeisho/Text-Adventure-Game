#include <stdio.h>
#include "getTemperatureInput.h"

double convertFromKelvinToCelsius(double temperatureInKelvin) {
  double result = temperatureInKelvin - 273.15;
  return result;
}

double convertFromKelvinToFarenheit(double temperatureInKelvin) {
  double result = convertFromKelvinToCelsius(temperatureInKelvin) * 9/5 + 32;
  return result;
}

void convertKelvinValues(char toInput) {
  double result;
  double input = getTemperatureInput();
  switch (toInput) {
    case 'C':
      result = convertFromKelvinToCelsius(input);
      printf("%.2f Kelvin equals %.2f Celsius.\n", input, result);
      break;
    case 'F':
      result = convertFromKelvinToFarenheit(input);
      printf("%.2f Kelvin equals %.2f Farenheit.\n", input, result);
      break;
    default:
      printf("How did you even get here?\n");
      break;
  }
}