#include <stdio.h>
#include <string.h>

int main() {
    char name[30];
    printf("What is your name?: ");
    fgets(name, sizeof(name), stdin);
    fputs("Your name is: ", stdout);
    name[strcspn(name, "\n")] = '\0';
    fputs(name, stdout);
    fputs(".\n", stdout);
    printf("Your name is: %s.\n", name);
}