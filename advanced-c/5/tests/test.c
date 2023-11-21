#include <criterion/criterion.h>

#include "../src/linked-list.h"

Test(linkedlist, generate) {
    LinkedList* list = generateLinkedList();
    cr_expect(list, "linked list should not be a null pointer");
}