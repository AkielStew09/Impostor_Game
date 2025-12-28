#include "./functions.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    clr();
    printf("Welcome to Impostor the game! \nGet your players ready and agree"
           " on an ordering among yourselves.\nPress enter to play.");
    getchar();

    printf("How many players are there?: ");
    int playerAmt;
    scanf("%d", &playerAmt);

    display(playerAmt);
}

// int main() {
//     clr();
//     printf("\nHello World, please show me.\n");
//     sleep(6);
// }
