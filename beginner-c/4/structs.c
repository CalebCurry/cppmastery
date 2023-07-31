#include <stdio.h>
#include <string.h>

int main() {
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

    Clue clues[12] = {{{5, 10}, {1, 1, 2019, 12, 12}, "lemonade"},
                      {{10, 10}, {1, 1, 2019, 12, 20}, "secrets"},
                      {{15, 10}, {1, 1, 2019, 18, 12}, "pizza"},
                      [8] = {{25, 10}, {1, 1, 2024, 18, 12}, "tacos"},
                      [10].secretWord = "chess"};

    for (int i = 0; i < 12; i++) {
        if (strcmp(clues[i].secretWord, "pizza") == 0) {
            printf("You found the correct word!");
        } else {
            printf("%s is incorrect\n", clues[i].secretWord);
        }
    }
    return 0;
}