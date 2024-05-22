#include <iostream>
#include <memory>

template <typename T>
class Node {
   public:
    T data;
    std::shared_ptr<Node<T>> next = nullptr;

    Node(T data) : data(data) {}

    Node() = default;
};

template <typename T>
class LinkedList {
    int _size = 0;

   public:
    std::shared_ptr<Node<T>> start = nullptr;
    std::shared_ptr<Node<T>> end = nullptr;

    int size() { return _size; }  // only getter

    void push(T data) {
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(data);
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
            start = nullptr;
            end = nullptr;
            _size--;
            return result;
        }
        // get the 2nd to last node
        std::shared_ptr<Node<T>> current = start;
        while (current->next != end) {
            // move to the next node
            current = current->next;
        }
        // at 2nd to last node
        auto result = current->next->data;
        current->next = nullptr;
        end = current;

        _size--;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const LinkedList<T>& list) {
        std::shared_ptr<Node<T>> current = list.start;
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
    LinkedList<int> list;
    list.push(5);
    list.push(50);
    list.push(500);
    list.pop();
    std::cout << list << std::endl;
}