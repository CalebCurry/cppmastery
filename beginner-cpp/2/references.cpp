#include <algorithm>
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
    std::vector<int> dest(data.size());

    std::for_each(data.begin(), data.end(), [](auto& d) { d *= 2; });
    std::transform(data.begin(), data.end(), dest.begin(),
                   [](auto d) { return d * 2; });

    printData(data);
    printData(dest);
}