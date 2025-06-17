#include <stdlib.h>
#include <stdio.h>

#define TRUE 1

double getTemperatureInput() {
  char buffer[100];
  char *endPtr;
  double input;

  while (TRUE) {
    printf("Enter temperature: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      input = strtod(buffer, &endPtr);

      if (endPtr != buffer && (*endPtr == '\n' || *endPtr == '\0')) {
        break;
      } else {
        printf("Invalid input! Please enter a number.\n");
        continue;
      }
    }
  }
  return input;
}