#include <stdio.h>
#include <ctype.h>
#include "Converters/kelvin.h"
#include "getInput.h"
#include "./Converters/celsius.h"
#include "./Converters/farenheit.h"

int main() {
  printf("=================================\n\n");
  printf("Welcome to the Farenheit / Celsius / Kelvin converter!\n");
  printf("To get started, please write what type you are converting from...\n");

  char fromInput = getInput();
  char fromInputUppercase = toupper(fromInput);

  switch (fromInputUppercase) {
    case 'C':
      printf("You chose Celsius, ");
      break;
    case 'F':
      printf("You chose Farenheit, ");
      break;
    case 'K':
      printf("You chose Kelvin, ");
      break;
    default:
      printf("You somehow broke the program... ");
      break;
  }

  printf("now write what you want to convert your temperature into...\n");
  char toInput = getInput();
  char toInputUppercase = toupper(toInput);

  if (fromInputUppercase == toInputUppercase) {
    printf("You chose the same tempereature scale, meaning the conversion "
            "will stay the same... goodbye!\n");
    return 0;
  }

  switch (fromInputUppercase) {
    case 'C':
      convertCelsiusValues(toInputUppercase);
      break;
    case 'F':
      convertFarenheitValues(toInputUppercase);
      break;
    case 'K':
      convertKelvinValues(toInputUppercase);
      break;
    default:
      printf("You somehow broke the program... ");
      break;
  }
  printf("=================================\n\n");
  return 0;
}