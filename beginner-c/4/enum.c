#include <stdio.h>

int main() {
    printf("Choose a difficulty:\n");
    printf("0. Easy\n");
    printf("1. Medium\n");
    printf("2. Hard\n");

    char DifficultyNames[][7] = {"easy", "medium", "hard"};
    typedef enum { EASY, MEDIUM, HARD } Difficulty;

    Difficulty difficulty;
    scanf("%i", &difficulty);
    printf("You chose %s.\n", DifficultyNames[difficulty]);

    return 0;
}