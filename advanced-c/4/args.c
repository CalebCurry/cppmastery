#include <stdio.h>

void printData(int size, char** data) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", data[i]);
    }
}

int main(int argc, char** argv) {
    // char* data[] = {"Caleb", "Mason", "Veronica", "Lizzie", "Emily"};
    printData(argc - 1, argv + 1);
    return 0;
}