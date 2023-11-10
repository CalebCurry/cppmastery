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
    if (*count >= *size) {
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
    int count = 0;
    int size = 5;
    int* array = generateArray(size);

    int grade;
    double total = 0;
    while (1) {
        printf("Enter a grade (-1 to quit): ");

        scanf("%i", &grade);
        if (grade == -1) {
            break;
        }
        total += grade;
        if (pushBack(&array, &size, &count, grade) != 0) {
            printf("Out of memory");
            break;
        }
        printArrayDetails(array, size, count);
    }
    printf("Average grade: %f\n", total / count);

    free(array);
    return 0;
}