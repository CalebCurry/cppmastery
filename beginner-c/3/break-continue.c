#include <stdio.h>

int main() {
    int guess;
    int correct[] = {50, 51, 52, 53, 54};

    int location = 0;
    printf("Guess 5 numbers one at a time: ");
    while (1) {
        scanf("%i", &guess);
        if (guess == correct[location]) {
            printf("Correct! You guessed %i\n", guess);
            location++;
            if (location == 5) {
                break;
            }
            printf("You have %i guesses left.\n", 5 - location);
            continue;
        }
        printf("Try again: ");
    }
    printf("Thanks for playing!\n");
    return 0;
}
