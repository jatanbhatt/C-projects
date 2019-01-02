/* MvM, 20 Game */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i;

  srand(time(NULL));// Init random

  for (int n = 0; n < 20; n++) {
      i = rand() % 6 + 1; // Random number
      printf("Random %d\n", i);
  }

  return(0);
};
