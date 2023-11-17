#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[256];
    double sum = 0;
    char* end = 0;
    int count = 0;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    char* token = strtok(buffer, " ");
    while (token != NULL) {
        double value = strtod(token, &end);

        if (*end != 0) {
            printf("Encountered character %c\n", *end);
            return 1;
        }

        sum += value;
        count++;
        token = strtok(NULL, " ");
    }

    if (count < 2) {
        printf("Please provide atleast 2 values\n");
        return 1;
    }

    printf("%f / %i = %f\n", sum, count, sum / count);
}