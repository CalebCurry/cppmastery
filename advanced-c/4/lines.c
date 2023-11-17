#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("names.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char* data = NULL;
    size_t size;

    while (getline(&data, &size, file) > 0) {
        printf("%s", data);
    }

    free(data);

    return 0;
}