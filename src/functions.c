#include "./bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// declarations
// clear the screen
void clr();

// use randomness to return the impostor num given the player amount
int getImpostor(int playerAmt);

// The main display of the game
void display(int playerAmt);

// Shows appropriate message to each player
void printMsg(int playerNum, int isImpostor, const char *keyword);

// Transitions for the given duration
void transition(int sec);

// get the keyword given the array and the size
const char *getWord(const char *arr[], int bankSize);

void display(int playerAmt) {
    srand(time(NULL));
    int impostor = getImpostor(playerAmt);
    int isImpostor = 0;

    const char *keyword = getWord(wordbank, wordBankSize);

    for (int i = 1; i <= playerAmt; ++i) {
        // check whethere it's the impostor
        if (i == impostor)
            isImpostor = 1;
        else
            isImpostor = 0;

        transition(5);
        // print appropriate message to player
        printMsg(i, isImpostor, keyword);

        // transition between messages
        transition(5);
    }

    printf("Setup up complete! Have fun! \n");
}

int getImpostor(int playerAmt) {
    // using mod on the rand returns from 0 -> num-1.
    // adding 1 returns from 1 -> num.
    // which is what I want
    int impostor = (rand() % playerAmt) + 1;
    return impostor;
}

void printMsg(int playerNum, int isImpostor, const char *keyword) {

    clr();

    if (!isImpostor) {
        printf("Player number %d, The keyword is: \n\n", playerNum);
        printf("\"%s\" \n\n", keyword);
    } else {
        printf("Player number %d, you are the IMPOSTOR!!\n\n", playerNum);
        printf("You do not get to see the keyword. Try to blend in, good luck! "
               "\n\n");
    }

    // printf("This message shows for 6 seconds...\n");
    sleep(6);
}

void transition(int sec) {
    // clear what was there
    clr();
    // show my message
    printf("Wait for %d second transition... \n", sec);
    // // flush the buffer
    // fflush(stdout);

    // leave the message there for some time
    sleep(sec);
}

void clr() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
    fflush(stdout);
#endif
}

const char *getWord(const char *arr[], int bankSize) {
    // get index of keyword given the bankSize
    int index = rand() % bankSize;
    return arr[index];
}
