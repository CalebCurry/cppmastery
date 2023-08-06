#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int month;
    int day;
    int year;
    int hour;
    int minute;
} DateTime;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    DateTime timeFound;
    char secretWord[25];
} Clue;

Clue newClue(char* secretWord, Position position) {
    Clue newClue = {0};

    if (secretWord == NULL || strlen(secretWord) == 0) {
        char wordList[][20] = {
            "apple",      "banana",     "cherry",    "orange",    "peach",
            "pear",       "grape",      "kiwi",      "mango",     "pineapple",
            "strawberry", "watermelon", "blueberry", "raspberry", "blackberry",
            "lemon",      "lime",       "coconut",   "papaya",    "apricot"};
        int randomIndex = rand() % 20;
        strcpy(newClue.secretWord, wordList[randomIndex]);
    } else {
        size_t size = sizeof(newClue.secretWord);
        strncpy(newClue.secretWord, secretWord, size - 1);
        newClue.secretWord[size - 1] = 0;
    }

    if (position.x < 0 || position.y < 0) {
        newClue.position.x = rand() % 30;
        newClue.position.y = rand() % 30;
    } else {
        newClue.position = position;
    }

    return newClue;
}

int main() {
    srand(time(NULL));
    Clue clues[] = {newClue("ABCDEFGHIJKLMNOPQRSTUVWXYZ", (Position){1, 1}),
                    newClue("pizza", (Position){15, 5}),
                    newClue("secrets", (Position){10, 10}),
                    newClue("delight", (Position){10, 20})};

    DateTime dt = {10, 10, 10, 10, 10};
    clues[0].timeFound = dt;

    printf("%s\n", clues[0].secretWord);
    printf("%i %i\n", clues[0].position.x, clues[0].position.y);
}