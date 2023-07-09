#include <stdio.h>

int main() {
    char names[5][50] = {"Alice", "Bob", "Charlie", "David", "Emily"};
    double grades[5] = {94.2, 65, 95.9, 92.3, 100};

    int index;
    printf("Provide us an index to get the name (0-4):");
    scanf("%i", &index);

    printf("The name at index %i is %s. Grade is %f.\n", index, names[index],
           grades[index]);

    /*
        names --> an array of char arrays
        names[x] --> char array
        names[x][y] --> char
    */

    printf("%c\n", names[4][0]);

    return 0;
}