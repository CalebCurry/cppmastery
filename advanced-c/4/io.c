#include <stdio.h>

int main() {
    char first[20];
    char last[20];
    char c;
    scanf("%19s", first);
    scanf("%19s", last);

    while ((c = getchar()) != '\n')
        ;

    scanf("%c", &c);
    printf("%s %s %c\n", first, last, c);
    return 0;
}