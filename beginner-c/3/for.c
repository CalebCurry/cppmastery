#include <stdio.h>

int main() {
    char names[][50] = {"Alice", "Bob", "Charlie", "David", "Emily", "Amber"};
    int grades[6];
    double sum = 0;

    int size = sizeof(grades) / sizeof(grades[0]);

    for (int i = 0; i < size; i++) {
        printf("%s exam score was: ", names[i]);
        scanf("%i", &grades[i]);
    }

    for (int i = size - 1; i >= 0; i--) {
        printf("%s got a grade of %i\n", names[i], grades[i]);
        sum += grades[i];
    }

    printf("The class average was %f.\n", sum / size);

    return 0;
}