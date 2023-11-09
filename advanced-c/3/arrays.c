#include <stdio.h>
#include <stdlib.h>

int* generateArray(int size) {
    int* array = malloc(sizeof(int) * size);

    if (array == NULL) {
        return NULL;
    }

    return array;
}

int* initializeArray(int* data, int count) {
    int* array = generateArray(count);
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < count; i++) {
        array[i] = data[i];
    }
    return array;
}

int pushBack(int** array, int* size, int* count, int value) {
    printf("pushback %i\n", value);
    if (*count >= *size) {
        printf("doubling size\n");
        int* temp = realloc(*array, sizeof(int) * (*size) * 2);
        if (temp == NULL) {
            return 1;
        }
        *array = temp;
        *size *= 2;
    }
    (*array)[*count] = value;
    (*count)++;
    return 0;
}

void printArrayDetails(int* array, int size, int count) {
    for (int i = 0; i < count; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
    printf("count: %i, size: %i\n", count, size);
}

int main() {
    int count = 5;
    int size = count;

    int data[] = {5, 10, 15, 20, 25};

    int* array = initializeArray(data, count);

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printArrayDetails(array, size, count);

    pushBack(&array, &size, &count, 30);
    printArrayDetails(array, size, count);

    free(array);
    return 0;
}