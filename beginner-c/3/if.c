#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    char correct[50] = "tacos";
    printf("Guess the password: ");
    scanf("%s", password);
    printf("You guessed %s\n", password);

    int code;
    int correct_code = 30;

    printf("Guess the code: ");
    scanf("%i", &code);
    printf("You guessed %i\n", code);

    int result = strcmp(password, correct);

    if (result == 0 && code == correct_code) {
        printf("Great job!\n");
    } else {
        if (result != 0) {
            printf("Password is wrong\n");
        }
        if (code != correct_code) {
            printf("Code is wrong\n");
        }
        printf("Feel free to try again.\n");
    }
    return 0;
}
