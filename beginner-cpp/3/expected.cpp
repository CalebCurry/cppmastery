#include <expected>
#include <iostream>
#include <vector>

std::expected<int, std::string> get(const std::vector<int>& data,
                                    long unsigned int index) {
    if (index < data.size()) {
        return data.at(index);
    } else {
        return std::unexpected("Out of bounds");
    }
}

int main() {
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

    long unsigned int index;
    std::cin >> index;

    auto result = get(data, index);

    if (result.has_value()) {
        std::cout << *result << std::endl;
    } else {
        std::cout << result.error() << std::endl;
    }

    // don't just do this:
    // std::cout << *option << std::endl;
}