#include <stdio.h>
#include <string.h>

typedef struct {
    int age;
    int* score;
    int points[30];
    char first[30];
    char* last;
} Person;

void printPerson(Person p) {
    printf("%i %i %i %s %s\n", p.age, *p.score, p.points[0], p.first, p.last);
}

void modifyPersonByValue(Person p) {
    p.age = -9000;
    *p.score = -9000;
    p.points[0] = -9000;
    strcpy(p.first, "Katie");
    strcpy(p.last, "Couric");
}

void modifyPersonByPointer(Person* p) {
    p->age = -9000;
    *p->score = -9000;
    p->points[0] = -9000;
    strcpy(p->first, "Katie");
    strcpy(p->last, "Couric");
}

int main() {
    int score = 5;
    char last[] = "Curry";

    Person caleb = {5, &score, {5, 5, 5}, "Caleb", last};
    printPerson(caleb);
    modifyPersonByPointer(&caleb);
    printPerson(caleb);

    return 0;
}