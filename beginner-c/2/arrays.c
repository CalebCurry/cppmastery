#include <stdio.h>

int main() {
    int grades[5];

    int gradeCount = 3;
    grades[0] = 10;
    grades[1] = 20;
    grades[2] = 30;

    for (int i = 0; i < gradeCount; i++) {
        printf("%i\t", grades[i]);
    }

    return 0;
}