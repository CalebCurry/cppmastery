#include <stdio.h>

int main() {
    typedef enum { INT, DOUBLE, STRING } Type;

    typedef struct {
        void* pointer;
        Type type;
    } VoidPointer;

    int age = 20;
    double score = 5.5;
    char fn[] = "Caleb";
    char ln[] = "Curry";

    // void* data[] = {&age, &score, &fn, &ln};
    // int types[] = {INT, DOUBLE, STRING, STRING};

    VoidPointer pointers[] = {
        {&age, INT}, {&score, DOUBLE}, {fn, STRING}, {ln, STRING}};

    for (int i = 0; i < 4; i++) {
        switch (pointers[i].type) {
            case INT:
                printf("%i\n", *(int*)pointers[i].pointer);
                break;
            case DOUBLE:
                printf("%f\n", *(double*)pointers[i].pointer);
                break;
            case STRING:
                printf("%s\n", (char*)pointers[i].pointer);
                break;
        }
    }

    // printf("%i %f %s", *(int*)data[0], *(double*)data[1], (char*)data[2]);
    return 0;
}