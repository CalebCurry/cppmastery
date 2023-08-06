#include <stdio.h>
#include <string.h>

void printMenu() {
    printf("Choose an option:\n");
    printf("0. Play a local game.\n");
    printf("1. Play an online game.\n");
    printf("2. View top scores.\n");
    printf("3. Exit.\n");
}

void printPoints(int points) { printf("You have %i points.\n", points); }

int calculateBonus(points) {
    if (points < 100) {
        return points * 2;
    } else {
        return points * 3;
    }
}

void welcomeUser(char fn[], char ln[]) {
    printf("Welcome to the game %s %s!\n", fn, ln);
}

int lengthWithSpace(char* fn, char* ln) {
    fn[0] = 'K';
    return strlen(fn) + 1 + strlen(ln);
}

void concatNames(char name[], char fn[], char ln[]) {
    strcpy(name, fn);
    strcat(name, " ");
    strcat(name, ln);
}

void readData(int* data, int size) {
    printf("Reading %i values\n", size);

    for (int i = 0; i < size; i++) {
        printf("Enter an int: ");
        scanf("%i", &data[i]);
        printf("%i left to fill...\n", size - 1 - i);
    }
}

void printData(int* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", data[i]);
    }
    printf("\n");
}

void print2D(int rows, int cols, int data[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%i ", data[i][j]);
        }
    }
}

int main() {
    int scores[][4] = {{1, 2, 3, 3}, {4, 5, 6, 6}, {7, 8, 9, 9}};

    int rows = sizeof(scores) / sizeof(scores[0]);
    int cols = sizeof(scores[0]) / sizeof(scores[0][0]);

    printf("%i %i\n", rows, cols);

    print2D(rows, cols, scores);
    return 0;
}