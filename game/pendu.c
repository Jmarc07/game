#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void displayCurrentState(char *word, char *guessedword)
{
    printf("Current word: %s\n", guessedword);
}

int iswordGuessed(char *word, char *guessedword) {
    return strcmp(word, guessedword) == 0;
}

void updateGuessedword(char *word, char *guessedword, char guess)
{
    for (int i = 0; i < strlen(word); i++) {
        if (tolower(word[i]) == guess) {
            guessedword[i] = word[i];
        }
    }
}

void getGuess(char *guess)
{
    printf("Enter a letter: ");
    scanf(" %c", guess);
    *guess = tolower(*guess);
}

int main(void)
{
    char word[] = "programming";
    int wordLength = strlen(word);
    char guessedword[wordLength + 1];
    memset(guessedword, '_', wordLength);
    guessedword[wordLength] = '\0';
    int attempts = 6;
    char guess;

    while (attempts > 0 && !iswordGuessed(word, guessedword)) {
        displayCurrentState(word, guessedword);
        getGuess(&guess);

        if (strchr(word, guess)) {
            updateGuessedword(word, guessedword, guess);
        } else {
            attempts--;
            printf("Wrong guess! Attempts left: %d\n", attempts);
        }
    }
    if (iswordGuessed(word, guessedword)) {
        printf("Congratulations! You've guessed the word: %s\n", word);
    } else {
        printf("You've run out of attempts! The word was: %s\n", word);
    }
    return 0;
}
