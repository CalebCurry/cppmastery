#include <iostream>

constexpr int square(int a) { return a * a; }

constexpr bool debug = true;

template <typename T>
void log(const T& message) {
    if constexpr (debug) {
        std::cout << message << std::endl;
    }
}

int main() {
    constexpr int x = 5;
    constexpr int result = square(x);
    log(result);
}