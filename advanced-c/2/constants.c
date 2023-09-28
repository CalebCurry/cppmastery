#include <stdio.h>

void print() {
    static int x = 5;
    printf("%i\n", x);
    x++;
}

int main() {
    print();
    print();
    print();
    print();
    print();
    return 0;
}