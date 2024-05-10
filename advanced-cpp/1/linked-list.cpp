#include <iostream>

class Node {
   public:
    int data;
    Node* next = nullptr;

    Node(int data) : data(data) {}

    Node() = default;
};

class LinkedList {
   public:
    ~LinkedList() {
        // iterate through the nodes
        // free each one
        Node* current = start;
        while (current != nullptr) {
            Node* temp = current->next;
            std::cout << "deleting " << current->data << std::endl;
            delete current;
            current = temp;
        }
    }

    Node* start = nullptr;

    void push(int data) {
        Node* node = new Node(data);
        if (start == nullptr) {
            // assign to start
            start = node;
        } else {
            // append to start's next
            // or go to the end of the list
            Node* current = start;
            while (current->next != nullptr) {
                current = current->next;
            }
            // we know current is the last node
            current->next = node;
        }
    }
};

int main() {
    LinkedList list;

    list.push(5);
    list.push(10);
    list.push(15);

    std::cout << list.start->data << std::endl;              // 5
    std::cout << list.start->next->data << std::endl;        // 10
    std::cout << list.start->next->next->data << std::endl;  // 15
}