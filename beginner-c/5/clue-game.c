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

void newClues(Clue clues[], int size) {
    for (int i = 0; i < size; i++) {
        clues[i] = newClue(NULL, (Position){-1, -1});
    }
}

void printClue(Clue clue) {
    if (clue.timeFound.year != 0) {
        printf("(%i, %i): %s found on: %i %i %i %i %i\n", clue.position.x,
               clue.position.y, clue.secretWord, clue.timeFound.year,
               clue.timeFound.month, clue.timeFound.day, clue.timeFound.hour,
               clue.timeFound.minute);
    }
}

void printClueAll(Clue clue) {
    printf("(%i, %i): %s found on: %i %i %i %i %i\n", clue.position.x,
           clue.position.y, clue.secretWord, clue.timeFound.year,
           clue.timeFound.month, clue.timeFound.day, clue.timeFound.hour,
           clue.timeFound.minute);
}

void printClues(Clue clues[], int size) {
    for (int i = 0; i < size; i++) {
        printClue(clues[i]);
    }
}

void printCluesAll(Clue clues[], int size) {
    for (int i = 0; i < size; i++) {
        printClueAll(clues[i]);
    }
}

bool positionEqual(Position p1, Position p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool find(Clue clues[], int size, Position p) {
    for (int i = 0; i < size; i++) {
        if (positionEqual(clues[i].position, p)) {
            // update time found
            time_t t = time(NULL);
            struct tm time = *localtime(&t);
            clues[i].timeFound.year = time.tm_year + 1900,
            clues[i].timeFound.month = time.tm_mon + 1;
            clues[i].timeFound.day = time.tm_mday;
            clues[i].timeFound.hour = time.tm_hour;
            clues[i].timeFound.minute = time.tm_min;
            return true;
        }
    }
    return false;
}

int main() {
    int size = 12;
    srand(time(NULL));
    Clue clues[size];
    newClues(clues, size);
    // printCluesAll(clues, size);
    //  printf("\n");
    //   find(clues, size, (Position){1, 3});
    //   printClues(clues, size);

    int x;
    int y;

    do {
        printf("Give me an x and a y, 5 5 for example. (-1 to quit): ");
        scanf("%i %i", &x, &y);
        if (x == -1 || y == -1) {
            break;
        }

        if (find(clues, size, (Position){x, y})) {
            printf("Found one!\n");
            printClues(clues, size);
        }

    } while (x != -1 && y != -1);

    return 0;
}