#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec(100000);
    std::iota(vec.begin(), vec.end(), 1);
    vec.at(10) = 70000;

    std::sort(std::execution::par, vec.begin(), vec.end());

    if (std::is_sorted(vec.begin(), vec.end())) {
        std::cout << "Sorted!" << std::endl;
    } else {
        std::cout << "NOT SORTED!" << std::endl;
    }
}