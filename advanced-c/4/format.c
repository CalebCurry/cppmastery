#include <stdio.h>

int main() {
    double x = 4700000000.74321234;
    // int x = 47;
    // int y = -470;
    // printf("%i %u %o %x %X\n", x, x, x, x, x);
    // printf("%0+8i\n%0+8i\n", x, y);
    printf("%0+g\n", x);
    return 0;
}