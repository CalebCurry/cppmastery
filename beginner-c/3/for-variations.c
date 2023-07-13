#include <stdio.h>

int main() {
    for (int i = 9, j = 0; i >= 0; j++, i -= 2) {
        printf("%i %i\n", i, j);
    }
    return 0;
}