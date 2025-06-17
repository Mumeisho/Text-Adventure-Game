#include "getInput.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  printf("=====================================\n\n");
  printf("Welcome to the random number guesser!\n");
  printf("I have a random number in mind that you have to guess.\nI will give "
         "subtle hints to help you out.\n");
  const int min = 1;
  const int max = 8421;
  const int randomNum = (rand() % (max - min + 1)) + min;

  int counter = 0;
  while (1) {
    counter++;
    int input = getInput();
    if (randomNum == input) {
      printf("That is correct!\n");
      break;
    }

    if (randomNum > input) {
      printf("Your number is smaller than my number.\n");
      continue;
    } else if (randomNum < input) {
      printf("Your number is bigger than my number.\n");
      continue;
    }
  }
  printf("You guessed the answer in %d tries!\n", counter);
  printf("=====================================\n\n");

  return 0;
}