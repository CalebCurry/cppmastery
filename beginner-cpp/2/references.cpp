#include <iostream>
#include <vector>

template <typename T>
void swapCustom(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;

    std::cout << x << " " << y << std::endl;
}

template <typename T>
void printData(const T data) {
    for (auto d : data) {
        std::cout << d << std::endl;
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    printData(data);
}