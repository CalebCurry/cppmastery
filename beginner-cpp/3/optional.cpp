#include <iostream>
#include <optional>
#include <vector>

std::optional<int> get(const std::vector<int>& data, long unsigned int index) {
    if (index < data.size()) {
        return data.at(index);
    } else {
        return {};
    }
}

int main() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

    long unsigned int index;
    std::cin >> index;

    auto option = get(data, index);

    if (option.has_value()) {
        std::cout << *option << std::endl;
    } else {
        std::cout << "Cannot access that index" << std::endl;
    }

    // don't just do this:
    // std::cout << *option << std::endl;
}