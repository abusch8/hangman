#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 128

void draw(int failed, char *guessed) {
    system("clear");
    printf(" +---+\n");
    printf(" |   |\n");
    switch(failed) {
        case 0:
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            break;
        case 1:
            printf(" |   O\n");
            printf(" |\n");
            printf(" |\n");
            break;
        case 2:
            printf(" |   O\n");
            printf(" |   |\n");
            printf(" |\n");
            break;
        case 3:
            printf(" |   O\n");
            printf(" |   |\\\n");
            printf(" |\n");
            break;
        case 4:
            printf(" |   O\n");
            printf(" |  /|\\\n");
            printf(" |\n");
            break;
        case 5:
            printf(" |   O\n");
            printf(" |  /|\\\n");
            printf(" |    \\\n");
            break;
        case 6:
            printf(" |   O\n");
            printf(" |  /|\\\n");
            printf(" |  / \\\n");
            break;
    }
    printf(" |\n");
    printf("========\n\n");
    for(int i = 0; i < strlen(guessed); i++) {
        printf("%c ", guessed[i]);
    }
    printf("\n\n");
    return;
}

int main(void) {
    char word[MAX_INPUT_SIZE];
    printf("Enter a word/sentence: ");
    fgets(word, sizeof(word), stdin);
    word[strlen(word) - 1] = '\0';
    char guessed[MAX_INPUT_SIZE] = "";
    for(int i = 0; i < strlen(word); i++) {
        guessed[i] = (isspace(word[i])) ? ' ' : '_';
    }
    guessed[strlen(guessed)] = '\0';
    int failed = 0;
    while(strcmp(word, guessed)) {
        draw(failed, guessed);
        if(failed >= 6) {
            printf("he deaded :(\n\n");
            return 0;
        }
        char guess[MAX_INPUT_SIZE];
        printf("Guess a letter or the entire word/sentence: ");
        fgets(guess, sizeof(guess), stdin);
        guess[strlen(guess) - 1] = '\0';
        bool correct = false;
        if(strlen(guess) == 1) {
            for(int i = 0; i < strlen(word); i++) {
                if(tolower(word[i]) == tolower(guess[0])) {
                    guessed[i] = guess[0];
                    correct = true;
                }
            }
        } else {
            if(!strcmp(word, guess)) {
                strcpy(guessed, guess);
                correct = true;
            }
        }
        if(!correct) failed++;
    }
    draw(failed, guessed);
    printf("correct! :)\n\n");
    return 0;
}
