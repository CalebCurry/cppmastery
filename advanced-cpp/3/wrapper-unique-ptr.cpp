#include <iostream>
#include <memory>

class Wrapper {
    std::unique_ptr<int> data;

   public:
    Wrapper(int data) : data(std::make_unique<int>(data)) {
        std::cout << "Allocating memory" << std::endl;
    }

    Wrapper(const Wrapper& from) : data(std::make_unique<int>(*from.data)) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Wrapper& operator=(const Wrapper& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this == &other) return *this;           // handle self-assignment
        data = std::make_unique<int>(*other.data);  // allocate the data
        return *this;
    }

    int getValue() { return *data; }
};

int main() {
    Wrapper w{5};
    Wrapper w2 = w;

    std::cout << w2.getValue() << " " << w.getValue() << std::endl;
}