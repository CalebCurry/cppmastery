#include <criterion/criterion.h>

#include "../src/linked-list.h"

// gcc -o linked-list-tests src/linked-list.c tests/test.c -lcriterion
// -I/opt/homebrew/include -L/opt/homebrew/lib

Test(linkedlist, generate) {
    LinkedList* list = generateLinkedList();
    cr_expect(list, "linked list should not be a null pointer");
}