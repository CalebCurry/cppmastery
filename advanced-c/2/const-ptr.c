#include <stdio.h>

int main() {
    int data = 5;
    const int* const pointer = &data;  // warning
    printf("%i\n", data);
}