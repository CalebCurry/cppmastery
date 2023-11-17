#include <stdio.h>
#include <string.h>

int main() {
    char data[] = "Hello\nmy\nname\nis\nCaleb";
    char* word = strtok(data, "\n");
    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, "\n");
    }
    return 0;
}