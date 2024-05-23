#include <iostream>

class Wrapper {
   public:
    int* data;
    Wrapper(int data) : data(new int(data)) {
        std::cout << "Allocating memory" << std::endl;
    }

    Wrapper(const Wrapper& from) : data(new int(*from.data)) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Wrapper(Wrapper&& from) noexcept : data(from.data) {
        from.data = nullptr;
        std::cout << "Move constructor called" << std::endl;
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

    Wrapper& operator=(Wrapper&& from) noexcept {
        std::cout << "Move operator assignment called" << std::endl;
        if (this == &from) {
            return *this;
        }
        delete data;
        data = from.data;
        from.data = nullptr;
        return *this;
    }

    ~Wrapper() {
        std::cout << "Deallocating memory" << std::endl;
        delete data;
    }
};

int main() {
    Wrapper w{5};
    Wrapper w2{10};
    w2 = std::move(w);
    // if needed check before accessing data
    // std::cout << *w.data << " " << *w2.data << std::endl;
}