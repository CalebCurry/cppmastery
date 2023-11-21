#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

void printNode(Node* node);

void printList(LinkedList* linkedList);

Node* createNode(int x, int y);

void pushBack(LinkedList* linkedList, int x, int y);

void pushFront(LinkedList* linkedList, int x, int y);

int size(LinkedList* linkedList);

Node* getNode(LinkedList* linkedList, int index);

Position get(LinkedList* linkedList, int index);

void set(LinkedList* linkedList, int index, int x, int y);

void insert(LinkedList* linkedList, int index, int x, int y);

Position* searchList(LinkedList* linkedList, int x, int y);

void freeList(LinkedList* linkedList);

LinkedList* generateLinkedList();

#endif