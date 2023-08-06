#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
    char secretWord[20];
} Clue;

bool isPasscodeCorrect(Clue attempt) {
    return strcmp(attempt.secretWord, "pizza") == 0 &&
           attempt.position.x == 15 && attempt.position.y == 5;
}

int main() {
    Clue clues[] = {
        {{5, 10}, {1, 1, 2019, 12, 12}, "lemonade"},
        {{15, 5}, {1, 1, 2019, 18, 12}, "pizza"},
        {{10, 10}, {1, 1, 2019, 12, 20}, "secrets"},
    };

    for (int i = 0; i < 3; i++) {
        printf("%i %i: %s\n", clues[i].position.x, clues[i].position.y,
               clues[i].secretWord);
        if (isPasscodeCorrect(clues[i])) {
            printf("You win!\n");
            break;
        } else {
            printf("Incorrect\n");
        }
    }
}