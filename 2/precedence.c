#include <stdio.h>
#include <string.h>

int main() {
    int test = 49;
    int grade = 10 + (test > 50 ? test : 50);  // guarenteed minimum of 60
    printf("%i\n", grade);

    printf("%f\n", 3.0 / 9.0 / 3.0);

    int a = 1;
    int b = 2;
    int c = 3;

    printf("a: %i, b: %i, c: %i\n", a, b, c);

    return 0;
}