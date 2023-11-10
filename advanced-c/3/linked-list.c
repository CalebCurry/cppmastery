#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct Node Node;

struct Node {
    Position data;
    Node* next;
};
typedef struct {
    Node* start;
    Node* end;
} LinkedList;

void printNode(Node* node) { printf("(%i, %i) ", node->data.x, node->data.y); }

void printList(LinkedList* linkedList) {
    Node* node = linkedList->start;
    while (node != 0) {
        printNode(node);
        node = node->next;
    }
    printf("\n");
}

Node* createNode(int x, int y) {
    Node* n = malloc(sizeof(Node));
    n->data.x = x;
    n->data.y = y;
    n->next = NULL;
    return n;
}

void pushBack(LinkedList* linkedList, int x, int y) {
    Node* new = createNode(x, y);
    new->next = 0;
    if (linkedList->start == NULL) {
        linkedList->start = new;
        linkedList->end = new;
        linkedList->end->next = NULL;
    } else {
        linkedList->end->next = new;
        linkedList->end = new;
    }
}

LinkedList* generateLinkedList() {
    LinkedList* linkedList = malloc(sizeof(LinkedList));
    linkedList->start = NULL;
    linkedList->end = NULL;
    return linkedList;
}

int main() {
    LinkedList* linkedList = generateLinkedList();
    printList(linkedList);
    pushBack(linkedList, 0, 1);
    pushBack(linkedList, 1, 2);
    pushBack(linkedList, 2, 3);
    pushBack(linkedList, 5, 7);
    pushBack(linkedList, 8, 8);
    pushBack(linkedList, 8, 9);
    pushBack(linkedList, 9, 9);
    printList(linkedList);
    return 0;
}