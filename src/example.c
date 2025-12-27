#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int playerAmt;
  printf("Enter player amount: ");
  scanf("%d", &playerAmt);

  for (int i = 0; i < 15; ++i) {
    int chosen = (rand() % playerAmt) + 1;
    printf("%d\n", chosen);
  }
}
