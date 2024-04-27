#include <array>
#include <iostream>
#include <vector>

int main() {
    double price = 4;
    double max = 5;
    double purchaseCount = 0;
    auto isCheap = [max, &purchaseCount]<typename T>(T price) {
        if (price <= max) {
            purchaseCount++;
            return true;
        }
        return false;
    };

    std::cout << isCheap(price) << std::endl;

    if (purchaseCount > 0) {
        std::cout << "Enjoy your purchase" << std::endl;
    }

    auto example = []<typename T>(std::vector<T> data) {
        std::cout << data[0] << std::endl;
    };

    auto data = std::vector<int>({1, 2, 3});

    example(data);

    auto div = []<typename T>(T a, T b) { return a / b; };
    std::cout << div(5.7, 5.5) << std::endl;
}