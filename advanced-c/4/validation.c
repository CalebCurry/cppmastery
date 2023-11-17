#include <ctype.h>
#include <stdio.h>

int isString(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int age;
    char name[30];

    do {
        printf("Enter your first name and age (example: Caleb 50): ");
    } while (scanf("%29s %i", name, &age) != 2 || !isString(name));
    printf("Hello %s (age %i)\n", name, age);

    // printf("Enter your first name and age (example: Caleb 50): ");
    // if (scanf("%29s %i", name, &age) != 2) {
    //     printf("Invalid input\n");
    // } else if (!isString(name)) {
    //     printf("Invalid name format\n");
    // } else {
    //     printf("Hello %s (age %i)\n", name, age);
    // }
}