#include <stdio.h>
#include <string.h>

int main() {
    printf("Guess my name: ");
    char name[] = "Caleb";

    char guess[50];
    scanf("%49s", guess);

    int points = (!strcmp(name, guess)) ? 30 : 0;
    printf("%i\n", points);
    return 0;
}