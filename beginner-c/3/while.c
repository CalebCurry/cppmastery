#include <stdio.h>

int main() {
    char c = '\0';
    while (c != 'q') {
        printf("Enter a key: ");
        scanf(" %c", &c);  // skip whitespace
        printf("You entered %c\n", c);
        char name[50];
        scanf("%s");
        // while (getchar() != '\n') { //this will clear multiple chars
        // }
    }
    return 0;
}
