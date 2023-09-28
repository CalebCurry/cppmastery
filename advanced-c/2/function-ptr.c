#include <stdio.h>

int square(int a) { return a * a; }
int dbl(int a) { return a * 2; }

void map(int* data, int size, int (*fn)(int)) {
    for (int i = 0; i < size; i++) {
        data[i] = (*fn)(data[i]);
    }
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", data[i]);
    }
    printf("\n");
}

int main() {
    const int size = 5;
    int data[] = {1, 2, 3, 4, 5};
    map(data, size, &square);
    printArray(data, size);
    map(data, size, &dbl);
    printArray(data, size);
    return 0;
}