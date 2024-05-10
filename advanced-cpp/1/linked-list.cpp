#include <iostream>

class Node {
   public:
    int data;
    Node* next = nullptr;

    Node(int data) : data(data) {}

    Node() = default;
};

class LinkedList {
    int _size = 0;

   public:
    Node* start = nullptr;
    Node* end = nullptr;

    int size() { return _size; }  // only getter
    ~LinkedList() {
        // iterate through the nodes
        // free each one
        Node* current = start;
        while (current != nullptr) {
            Node* temp = current->next;
            delete current;
            current = temp;
        }
    }

    void push(int data) {
        Node* node = new Node(data);
        if (start == nullptr) {
            // assign to start
            start = node;
            end = node;
        } else {
            // setting the previous end's next to the new end
            end->next = node;  // makes the chain
            // update the end pointer
            end = node;
        }
        _size++;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        Node* current = list.start;
        while (current != nullptr) {
            if (current != list.end) {
                os << current->data << " -> ";
            } else {
                os << current->data;
            }
            current = current->next;
        }
        return os;
    }
};

int main() {
    LinkedList list;

    list.push(5);
    list.push(10);
    list.push(15);

    std::cout << list << std::endl;
}