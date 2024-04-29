#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
void printData(const T data) {
    for (auto d : data) {
        std::cout << d.name << "\t" << d.price << std::endl;
    }
    std::cout << "\n\n" << std::endl;
}

struct Product {
    std::string name;
    double price;
};

// apply a 10% off coupon
// only buy the "cheap" ones (<= 20)
// calculate total

int main() {
    std::vector<Product> products = {{"laptop charger", 25},
                                     {"keyboard", 22},
                                     {"mouse", 18},
                                     {"monitor", 30},
                                     {"cable", 5}};

    std::for_each(products.begin(), products.end(),
                  [](Product& product) { product.price *= .9; });

    printData(products);

    auto it =
        std::remove_if(products.begin(), products.end(),
                       [](Product& product) { return product.price > 20; });

    products.erase(it, products.end());

    printData(products);

    double sum = std::accumulate(
        products.begin(), products.end(), 0.0,
        [](double sum, Product& product) { return sum + product.price; });

    std::cout << sum << std::endl;
    std::cout << sum / products.size() << std::endl;
}