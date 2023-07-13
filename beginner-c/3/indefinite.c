#include <stdio.h>
#include <string.h>

int main() {
    const int MAX = 50;
    const int LENGTH = 50;
    // update scanf too
    char students[MAX][LENGTH];
    double grades[MAX];
    int index = 0;

    char name[LENGTH];

    printf("Enter a student name (one per line).\n");
    printf("Student %i: ", index + 1);
    scanf("%49s", name);

    while (strcmp(name, "end")) {
        strcpy(students[index], name);
        printf("Grade?: ");
        scanf("%lf", &grades[index]);
        index++;
        printf("Student %i: ", index + 1);
        scanf("%49s", name);
    }

    for (int i = 0; i < index; i++) {
        printf("Student %i: %s had a grade of %f\n", i + 1, students[i],
               grades[i]);
    }

    return 0;
}
