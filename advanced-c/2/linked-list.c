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

Node* getNode(Node* start, int index) {
    Node* node = start;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

Node* searchList(Node* start, int x, int y) {
    Node* node = start;
    while (node != 0) {
        if (node->data.x == x && node->data.y == y) {
            return node;
        }
        node = node->next;
    }
    return 0;
}

int indexOf(Node* start, int x, int y) {
    Node* node = start;
    int count = 0;
    while (node != 0) {
        if (node->data.x == x && node->data.y == y) {
            return count;
        }
        node = node->next;
        count++;
    }
    return -1;
}

int size(Node* start) {
    Node* node = start;
    int count = 0;
    while (node != 0) {
        node = node->next;
        count++;
    }
    return count;
}

void printNode(Node* node) { printf("(%i, %i) ", node->data.x, node->data.y); }

void printList(Node* start) {
    Node* node = start;
    while (node != 0) {
        printNode(node);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node a = {{0, 1}, NULL};
    Node b = {{1, 2}, NULL};
    Node c = {{2, 3}, NULL};
    Node d = {{5, 7}, NULL};
    Node e = {{8, 8}, NULL};
    Node f = {{8, 9}, NULL};

    Node* start = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    f.next = 0;

    printList(start);

    Node* search = searchList(start, 9, 8);

    if (search) {
        printNode(search);
    }

    printf("%i\n", indexOf(start, 9, 8));

    printf("The linked list is size %i\n", size(start));

    return 0;
}