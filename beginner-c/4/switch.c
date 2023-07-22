#include <stdio.h>
#include <string.h>

int main() {
    int membership = 5;
    char message[50];

    // if (membership == 0 || membership == 1) {
    //     printf("Bronze\n");
    //     strcpy(message, "Welcome, cheapo");
    // } else if (membership == 2) {
    //     printf("Silver\n");
    //     strcpy(message, "Average");
    // } else if (membership > 2 && membership <= 5) {
    //     printf("Gold\n");
    //     strcpy(message, "You go above and beyond.");
    // }

    switch (membership) {
        case 0:
        case 1:
            printf("Bronze\n");
            strcpy(message, "Welcome, cheapo");
            break;
        case 2:
            printf("Silver\n");
            strcpy(message, "Average");
            break;
        case 3:
        case 4:
        case 5:
            printf("Gold\n");
            strcpy(message, "You go above and beyond.");
            break;
    }
    printf("%s\n", message);
    return 0;
}