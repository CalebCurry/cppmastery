#include <stdio.h>

typedef struct {
    int x;
    int y;
} Position;

void printPosition(Position p) { printf("%i %i\n", p.x, p.y); }

void swapPositions(Position* a, Position* b) {
    Position temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    Position a = {5, 10};
    Position b = {-20, -50};
    swapPositions(&a, &b);
    printPosition(a);
    printPosition(b);
    return 0;
}