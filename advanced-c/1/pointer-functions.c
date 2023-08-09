#include <stdio.h>

void modifyData(const int* data) {
    int newDestination = 9000;
    data = &newDestination;
    printf("%i\n", *data);
}

int main() {
    int age = 5;
    int* p = &age;
    modifyData(p);
    printf("%i\n", *p);
    return 0;
}