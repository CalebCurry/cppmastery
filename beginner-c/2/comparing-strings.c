#include <stdio.h>
#include <string.h>

int main() {
    char password1[50];
    char password2[50];

    while (strcmp(password1, password2)) {
        scanf("%49s", password1);
        scanf("%49s", password2);

        int equal = strcmp(password1, password2);

        printf("%i\n", equal);
    }
    return 0;
}