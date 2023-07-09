#include <stdbool.h>
#include <stdio.h>

int main() {
    // lets see the "index" of null terminating character
    char message[] = {'H', 'e', 'l', 'l', 'o'};

    printf("%s\n", message);
    int i = 0;
    while (true) {
        if (message[i] == '\0') {
            printf("%i\n", i);
            break;
        }
        i++;
    }
}