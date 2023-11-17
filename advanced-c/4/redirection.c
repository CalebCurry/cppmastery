#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[256];
    double sum = 0;
    char* end = 0;
    int count = 0;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (strcmp(buffer, "q\n") == 0) {
            break;
        }
        double value = strtod(buffer, &end);

        sum += value;
        count++;
    }

    if (count < 2) {
        printf("Please provide atleast 2 values\n");
        return 1;
    }

    printf("%f / %i = %f\n", sum, count, sum / count);
}