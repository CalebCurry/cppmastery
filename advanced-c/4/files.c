#include <stdio.h>

int main() {
    FILE* file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[256] = "This is an example!";
    // fgets(buffer, sizeof(buffer), file);
    fputs(buffer, file);
    printf("%s\n", buffer);

    fclose(file);
    return 0;
}