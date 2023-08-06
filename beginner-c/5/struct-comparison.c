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

bool equal(Clue a, Clue b) {
    return (a.position.x == b.position.x && a.position.y == b.position.y &&
            a.timeFound.day == b.timeFound.day &&
            a.timeFound.hour == b.timeFound.hour &&
            a.timeFound.minute == b.timeFound.minute &&
            a.timeFound.month == b.timeFound.month &&
            a.timeFound.year == b.timeFound.year &&
            strcmp(a.secretWord, b.secretWord) == 0);
}

int main() {
    Clue clues[] = {
        {{5, 10}, {1, 1, 2019, 12, 12}, "lemonade"},
        {{5, 10}, {1, 1, 2019, 12, 12}, "lemonade"},
        {{15, 5}, {1, 1, 2019, 18, 12}, "pizza"},
        {{10, 10}, {1, 1, 2019, 12, 20}, "secrets"},
    };

    if (equal(clues[0], clues[1])) {
        printf("They are the same");
    }
}