#include <iostream>
#include <memory>

auto getData() { return std::make_unique<int>(5); }

int main() {
    auto data = getData();
    auto ptr = std::move(data);
    // not use previous variable
    if (data) {
        std::cout << *ptr << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
}