#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> data = {5, 10, 15, 20, 25};
    std::vector<int> doubled;
    doubled.reserve(data.size());

    std::transform(data.begin(), data.end(), std::back_inserter(doubled),
                   [](auto value) { return value * 2; });

    for (auto d : data) {
        std::cout << d << std::endl;
    }
}