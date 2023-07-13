#include <stdio.h>

int i = 5;  // i0

int main() {
    i++;
    printf("%i\n", i);
    int i = 9;                      // i1
    for (int i = 9; i >= 0; i--) {  // i2
        printf("%i\n", i);          // i2
    }

    printf("%i\n", i);  // i1
    return 0;
}