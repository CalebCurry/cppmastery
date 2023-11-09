#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 10;
    int size = 10;
    int* array = malloc(sizeof(int) * count);

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        array[i] = i;
    }

    for (int i = 0; i < count; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    size *= 2;
    array = realloc(array, sizeof(int) * size);

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    array[10] = 10;
    count++;

    for (int i = 0; i < count; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}