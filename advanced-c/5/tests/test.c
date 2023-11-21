#include <criterion/criterion.h>

#include "../src/linked-list.h"

// gcc -o linked-list-tests src/linked-list.c tests/test.c -lcriterion
// -I/opt/homebrew/include -L/opt/homebrew/lib

LinkedList* list;
void setup(void) { list = generateLinkedList(); }

void teardown(void) { freeList(list); }

TestSuite(linkedlist, .init = setup, .fini = teardown);

Test(linkedlist, generate) {
    cr_expect(list, "linked list should not be a null pointer");
}

Test(linkedlist, pushBack) {
    pushBack(list, 6, 10);
    pushBack(list, 15, 20);

    cr_assert(list->start->data.x == 6);
    cr_assert(list->start->data.y == 10);
    cr_assert(get(list, 1).x == 15 && get(list, 1).y == 20,
              "Data should be (15, 20)");
}