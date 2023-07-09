#include <stdio.h>
#include <string.h>

int main() {
    char name[50] = "";
    char first[] = "Caleb";
    char last[6] = "";

    strcpy(last, first);

    strcat(name, first);
    strcat(name, " ");
    strcat(name, last);

    printf("%s %s\n", first, last);
    size_t length = strlen(name);
    printf("%s is %zu characters long.\n", name, length);
    return 0;
}