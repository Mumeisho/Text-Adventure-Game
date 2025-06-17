#include <stdio.h>
#include <string.h>

#define TRUE 1

void cleanInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

char getInput() {
  char buffer[100];
  char input;

  while (TRUE) {
    printf("(C / F / K): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      if (buffer[strlen(buffer) - 1] != '\n') {
        printf("Input is too long. Please enter only one character.\n");
        cleanInputBuffer();
        continue;
      }

      buffer[strlen(buffer) - 1] = '\0';

      if (strlen(buffer) == 1 &&
          (buffer[0] == 'C' || buffer[0] == 'c' || buffer[0] == 'F' ||
           buffer[0] == 'f' || buffer[0] == 'K' || buffer[0] == 'k')) {
        input = buffer[0];
        break;
      }
    }
    printf("Invalid input. Please enter one of the following characters...\n");
  }

  return input;
}