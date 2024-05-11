#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class Node {
   public:
    T data;
    Node* next = nullptr;

    Node(T data) : data(data) {}

    Node() = default;
};

template <typename T>
class LinkedList {
    int _size = 0;

   public:
    Node<T>* start = nullptr;
    Node<T>* end = nullptr;

    int size() { return _size; }  // only getter
    ~LinkedList() {
        // iterate through the nodes
        // free each one
        Node<T>* current = start;
        while (current != nullptr) {
            Node<T>* temp = current->next;
            delete current;
            current = temp;
        }
    }

    void push(T data) {
        Node<T>* node = new Node(data);
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

    T pop() {
        if (_size == 0) {
            throw std::runtime_error("List is empty");
        }
        if (_size == 1) {
            auto result = start->data;
            delete start;
            start = nullptr;
            end = nullptr;
            _size--;
            return result;
        }
        // get the 2nd to last node
        Node<T>* current = start;
        while (current->next != end) {
            // move to the next node
            current = current->next;
        }
        // at 2nd to last node
        auto result = current->next->data;
        delete current->next;
        current->next = nullptr;
        end = current;

        _size--;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const LinkedList<T>& list) {
        Node<T>* current = list.start;
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

#endif