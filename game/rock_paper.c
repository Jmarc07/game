#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

const char *choices[] = {"Rock", "Paper", "Scissors"};

void getComputerchoice(char *computerchoice)
{
    srand(time(0));
    int random = rand() % 3;
    *computerchoice = "RPS"[random];
}

void getuserchoice(char *userchoice)
{
    printf("Enter R for Rock, P for Paper, or S for Scissors: ");
    scanf(" %c", userchoice);
    *userchoice = toupper(*userchoice);
}

void determineWinner(char userchoice, char computerchoice)
{
    printf("You chose: %s\n", choices[(userchoice == 'R' ? 0 : (userchoice == 'P' ? 1 : 2))]);
    printf("Computer chose: %s\n", choices[(computerchoice == 'R' ? 0 : (computerchoice == 'P' ? 1 : 2))]);

    if (userchoice == computerchoice) {
        printf("It's a tie!\n");
    } else if ((userchoice == 'R' && computerchoice == 'S') ||
               (userchoice == 'P' && computerchoice == 'R') ||
               (userchoice == 'S' && computerchoice == 'P')) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

int main(void)
{
    char userchoice, computerchoice;
    getComputerchoice(&computerchoice);
    getuserchoice(&userchoice);
    determineWinner(userchoice, computerchoice);
    return 0;
}
