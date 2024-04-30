#include <iostream>
#include <vector>

void print(double d) { std::cout << d << std::endl; }
int print(double d, int x) {
    std::cout << d << std::endl;
    return 5;
}
void print(int d) { std::cout << d << std::endl; }

template <typename T>
void print(T data) {
    for (auto d : data) {
        std::cout << d << std::endl;
    }
}

int main() {
    print(5);
    print(std::vector<double>{5.5, 6.6, 7.7});
}