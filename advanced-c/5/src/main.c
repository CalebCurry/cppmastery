#include <stdio.h>

#include "linked-list.h"

// compile and run
// gcc -o main main.c linked-list.c && ./main
int main() {
    LinkedList* linkedList = generateLinkedList();
    printList(linkedList);
    pushFront(linkedList, 0, -1);
    pushBack(linkedList, 1, 2);
    pushBack(linkedList, 2, 3);
    pushFront(linkedList, 5, 7);
    pushBack(linkedList, 8, 8);
    pushBack(linkedList, 8, 9);
    pushBack(linkedList, 9, 9);
    printList(linkedList);
    insert(linkedList, 7, 5, 5);
    insert(linkedList, 8, 50, 50);
    insert(linkedList, 9, 500, 500);
    printList(linkedList);

    Position p = get(linkedList, 5);
    set(linkedList, 5, 300, 300);
    printf("(%i, %i)\n", p.x, p.y);
    printList(linkedList);
    Position* search = searchList(linkedList, 300, 300);
    search->x = 301;
    printList(linkedList);
    freeList(linkedList);
    return 0;
}