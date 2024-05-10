#include <iostream>

class Node {
   public:
    int data;
    Node* next;

    Node(int data) : data(data) {}

    Node() = default;
};

class LinkedList {
   public:
    Node* start;
};

int main() {
    Node a(5);
    Node b(10);
    Node c(15);

    LinkedList list;
    list.start = &a;

    a.next = &b;
    b.next = &c;

    std::cout << list.start->data << std::endl;              // a
    std::cout << list.start->next->data << std::endl;        // b
    std::cout << list.start->next->next->data << std::endl;  // c
}