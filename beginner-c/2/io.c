#include <stdio.h>

int main() {
    int age;
    char name[50];

    printf("Enter your name: ");
    scanf("%49s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Hi %s, You are %i years old\n", name, age);
    return 0;
}