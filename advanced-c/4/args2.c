#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char* end;
    double sum = 0;

    if (argc <= 2) {
        printf("Please include atleast 2 arg.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        sum += strtod(argv[i], &end);
        if (*end != 0) {
            printf("Error parsing args. Encountered character %c\n", *end);
            return 1;
        }
    }
    printf("Your average (%f / %i): %f.\n", sum, argc - 1, sum / (argc - 1));
    return 0;
}