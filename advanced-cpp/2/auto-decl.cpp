#include <iostream>
#include <vector>

double calculate(double x, double y) { return x * y; }

int main() {
    int x = 5;
    decltype(calculate(5.5, 3.3)) y = 10;

    std::vector<double> data{5, 10, 15};

    for (auto d : data) {
        std::cout << d << std::endl;
    }
}