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
    int count;
} LinkedList;

void printNode(Node* node) { printf("(%i, %i) ", node->data.x, node->data.y); }

void printList(LinkedList* linkedList) {
    printf("List count: %i: ", linkedList->count);
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
    linkedList->count++;
}

void pushFront(LinkedList* linkedList, int x, int y) {
    Node* new = createNode(x, y);
    if (linkedList->start == NULL) {
        linkedList->start = new;
        linkedList->end = new;
        linkedList->end->next = NULL;
    } else {
        new->next = linkedList->start;
        linkedList->start = new;
    }
    linkedList->count++;
}

int size(LinkedList* linkedList) {
    Node* node = linkedList->start;
    int count = 0;
    while (node != 0) {
        node = node->next;
        count++;
    }
    return count;
}

Node* getNode(LinkedList* linkedList, int index) {
    Node* node = linkedList->start;
    for (int i = 0; i < index; i++) {
        node = node->next;
        if (node == 0) {
            return NULL;
        }
    }
    return node;
}

Position get(LinkedList* linkedList, int index) {
    Node* node = getNode(linkedList, index);
    return node->data;
}

void set(LinkedList* linkedList, int index, int x, int y) {
    Node* node = getNode(linkedList, index);
    node->data.x = x;
    node->data.y = y;
}

void insert(LinkedList* linkedList, int index, int x, int y) {
    if (index == 0) {
        pushFront(linkedList, x, y);
    } else if (index == linkedList->count) {
        pushBack(linkedList, x, y);
    } else {
        Node* found = getNode(linkedList, index - 1);
        Node* new = createNode(x, y);
        new->next = found->next;
        found->next = new;
        linkedList->count++;
    }
}

Position* searchList(LinkedList* linkedList, int x, int y) {
    Node* node = linkedList->start;
    while (node != 0) {
        if (node->data.x == x && node->data.y == y) {
            return &(node->data);
        }
        node = node->next;
    }
    return 0;
}

void freeList(LinkedList* linkedList) {
    Node* node = linkedList->start;
    while (node != NULL) {
        Node* next = node->next;
        free(node);
        node = next;
    }
    free(linkedList);
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
    pushFront(linkedList, 0, 1);
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
    free(linkedList);
    return 0;
}