#include <stdbool.h>
#include <stdio.h>

int main() {
    // this shows that the additional indexes are initialized to 0
    // in other words, you don't need to explicitly end with \0 when providing a
    // larger size
    char numbers[30] = {'h', 'e', 'l', 'l', 'o'};
    for (int i = 0; i < 30; i++) {
        printf("%i ", numbers[i]);
    }
}