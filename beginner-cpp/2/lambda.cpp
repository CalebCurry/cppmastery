#include <iostream>

int main() {
    double price = 3;
    double max = 5;
    double purchaseCount = 0;
    auto isCheap = [max, &purchaseCount](double price) {
        if (price <= max) {
            purchaseCount++;
            return true;
        }
        return false;
    };

    std::cout << isCheap(price) << std::endl;

    std::cout << purchaseCount << std::endl;
}