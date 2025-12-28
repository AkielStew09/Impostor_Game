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
