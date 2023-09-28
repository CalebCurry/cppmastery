#include <stdio.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct Node Node;

struct Node {
    Position data;
    Node* next;
};

void printList(Node* start) {
    Node* node = start;
    while (node != 0) {
        printf("(%i, %i) ", node->data.x, node->data.y);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node a = {0, 1};
    Node b = {1, 2};
    Node c = {2, 3};
    Node d = {5, 7};
    Node e = {8, 8};
    Node f = {8, 9};

    Node* start = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    f.next = 0;

    printList(start);

    return 0;
}