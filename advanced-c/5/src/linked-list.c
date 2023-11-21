#include "linked-list.h"

#include <stdio.h>
#include <stdlib.h>

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
