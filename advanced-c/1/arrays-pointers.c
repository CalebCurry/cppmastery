#include <stdio.h>

typedef struct {
    int x;
    int y;
} Position;

int main() {
    Position p0 = {0, 0};
    Position p1 = {0, 5};
    Position p2 = {5, 5};
    Position p3 = {10, 5};
    Position p4 = {10, 10};

    Position positions[] = {p0, p1, p2, p3, p4};

    for (int i = 0; i < 5; i++) {
        printf("regular: %i %i\n", positions[i].x, positions[i].y);
    }

    // a pointer to an array
    // type (*pointerName)[size] = &someArray
    Position(*positionsPointer)[5] = &positions;
    for (int i = 0; i < 5; i++) {
        printf("pointer to an array: %i %i\n", (*positionsPointer)[i].x,
               (*positionsPointer)[i].y);
    }

    // an array of pointers
    // type* arrayName[size]
    // char* firstNames[] = {"Caleb"};
    Position* positionPointers[5] = {&p0, &p1, &p2, &p3, &p4};
    for (int i = 0; i < 5; i++) {
        printf("array of pointers: %i %i\n", positionPointers[i]->x,
               (*positionPointers[i]).y);
    }

    Position*(*positionPointersPointer)[5] = &positionPointers;
    for (int i = 0; i < 5; i++) {
        printf("pointer to an array of pointers: %i %i\n",
               (*positionPointersPointer)[i]->x,
               (*positionPointersPointer)[i]->y);
    }
    return 0;
}