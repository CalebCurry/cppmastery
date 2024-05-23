#include <iostream>
#include <memory>

class Wrapper {
   public:
    int data;
    std::weak_ptr<Wrapper> ptr;

    Wrapper(int data) : data(data) {
        std::cout << "Constructor called with " << data << std::endl;
    }

    ~Wrapper() { std::cout << "Destructor hit" << std::endl; }
};

int main() {
    auto w1 = std::make_shared<Wrapper>(10);
    auto w2 = std::make_shared<Wrapper>(100);

    w1->ptr = w2;
    w2->ptr = w1;

    auto ptr = w1->ptr.lock();
    if (ptr) {
        std::cout << ptr->data << std::endl;
    }

    // std::weak_ptr<int> weak;
    // std::shared_ptr<int> locked;
    // {
    //     std::shared_ptr<int> shared = std::make_shared<int>(5);
    //     weak = shared;
    //     locked = weak.lock();
    //     std::cout << locked.use_count() << std::endl;
    // }

    // std::cout << locked.use_count() << std::endl;
    // if (locked) {
    //     std::cout << *locked << std::endl;
    // }
}