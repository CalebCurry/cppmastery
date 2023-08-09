#include <stdio.h>

void changeValue(int** pointer, int* newAddr) {
    *pointer = newAddr;
    printf("%i\n", **pointer);
}

void printFullName(char* first, char* last) { printf("%s %s\n", first, last); }

void printFullNames(char** firstNames, char** lastNames, int count) {
    for (int i = 0; i < count; i++) {
        printFullName(firstNames[i], lastNames[i]);
    }
}

int main() {
    char* first[] = {"Caleb", "Alice", "Charlie"};
    char* last[] = {"Curry", "in Wonderland", "and the chocolate factory"};
    printFullNames(first, last, 3);
    //     int x = 5;
    //     int y = 10;
    //     int* pointer = &x;
    //     changeValue(&pointer, &y);
    //     printf("%i\n", *pointer);
    return 0;
}