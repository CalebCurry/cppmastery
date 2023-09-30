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
        if (node == 0) {
            return NULL;
        }
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

void pushFront(Node** start, Node* new) {
    new->next = *start;
    *start = new;
}

Node* findEnd(Node* start) {
    Node* node = start;
    while (node->next != 0) {
        node = node->next;
    }
    return node;
}

void pushBack(Node** end, Node* new) {
    new->next = 0;
    (*end)->next = new;
    *end = new;
}

void insertNode(Node** start, Node** end, Node* new, int index) {
    if (index == 0) {
        pushFront(start, new);
    } else {
        Node* found = getNode(*start, index - 1);
        new->next = found->next;
        found->next = new;

        // also need to check for valid index

        if (found->next->next == 0) {
            *end = new;
        }
    }
}

int main() {
    Node a = {{0, 1}, NULL};
    Node* start = &a;
    Node* end = start;
    printList(start);

    Node b = {{1, 2}, NULL};
    pushBack(&end, &b);
    Node c = {{2, 3}, NULL};
    pushBack(&end, &c);
    Node d = {{5, 7}, NULL};
    pushBack(&end, &d);
    Node e = {{8, 8}, NULL};
    pushBack(&end, &e);
    Node f = {{8, 9}, NULL};
    pushBack(&end, &f);

    printList(start);

    // insert beginning
    Node beginning = {{0, 0}, NULL};
    insertNode(&start, &end, &beginning, 0);
    printList(start);

    // insert middle
    Node middle = {{4, 4}, NULL};
    insertNode(&start, &end, &middle, 4);
    printList(start);

    // insert end
    Node last = {{10, 10}, NULL};
    insertNode(&start, &end, &last, 8);
    printList(start);

    Node last2 = {{11, 11}, NULL};
    pushBack(&end, &last2);
    printList(start);

    Node* retrieved = getNode(start, 9);
    if (retrieved != 0) {
        printNode(retrieved);
    }

    return 0;
}