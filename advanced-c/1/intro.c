#include <stdio.h>

int main() {
    int age = 5;
    int score = 30;
    int* p = &age;
    age = 10;
    p = &score;
    printf("%i %i\n", age, *p);
}