#include <stdio.h>

int main() {
    char students[50][50];
    double grades[50];
    int count = 0;

    printf("How many students do you want to store?: ");
    scanf("%i", &count);

    printf("Enter a student name (one per line).\n");
    for (int i = 0; i < count; i++) {
        printf("Student %i\n", i + 1);
        scanf("%49s", students[i]);
        printf("Grade?: ");
        scanf("%lf", &grades[i]);
    }

    for (int i = 0; i < count; i++) {
        printf("Student %i: %s had a grade of %f\n", i + 1, students[i],
               grades[i]);
    }

    return 0;
}
