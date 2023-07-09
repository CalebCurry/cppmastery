#include <stdbool.h>
#include <stdio.h>

int main() {
    int x = 42;
    float y = 3.14159f;
    double z = 2.718281828459045;
    char c = 'A';
    char str[] = "Hello, world!";
    bool b = true;

    printf("%i\n", x);
    printf("%f\n", y);
    printf("%f\n", z);
    printf("%c\n", c);
    printf("%s\n", str);
    printf("%i\n", b);

    return 0;
}