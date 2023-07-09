#include <stdio.h>
#include <string.h>

int main() {
    char name1[] = "Caleb";
    char name2[] = "Caleb";

    printf("Are they equal? (1 is true, 0 is false): %i\n",
           !strcmp(name1, name2));
    return 0;
}