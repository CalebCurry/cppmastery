#include <iostream>

class Wrapper {
   public:
    int* data;
    Wrapper(int data) : data(new int(data)) {
        std::cout << "Allocating memory" << std::endl;
    }

    Wrapper(const Wrapper& from) : data(new int(*from.data)) {
        std::cout << "Allocating memory" << std::endl;
    }

    Wrapper& operator=(const Wrapper& from) {
        std::cout << "Copy operator assignment called" << std::endl;
        if (this == &from) {
            return *this;
        }
        delete data;
        data = new int(*from.data);
        return *this;
    }

    ~Wrapper() {
        std::cout << "Deallocating memory" << std::endl;
        delete data;
    }
};

int main() {
    Wrapper w{5};
    Wrapper w2{500};
    w2 = Wrapper(w);
    std::cout << *w.data << " " << *w2.data << std::endl;
}