#include <stdio.h>

int main() {
    float x = 100.1;
    printf("%lu\n", sizeof x);
    return 0;
}

// 0 -> 0
// 1 --> 1
// 10 --> 2
// 11 --> 3
// 100 --> 4
// 101 --> 5
// 110 --> 6
// 111 --> 7
// 1000 --> 8