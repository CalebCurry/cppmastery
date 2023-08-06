#include <stdio.h>
#include <string.h>

typedef struct {
    char name[6];
} Wrapper;

void modifyNameWrapped(Wrapper w) {
    strcpy(w.name, "John");
    printf("%s\n", w.name);
}

void modifyName(char* name) { strcpy(name, "John"); }

int main() {
    Wrapper w = {"Caleb"};
    modifyNameWrapped(w);
    printf("%s\n", w.name);
    return 0;
}