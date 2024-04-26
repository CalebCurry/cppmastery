#include <array>
#include <iostream>

int main() {
    // std::vector<int> data = {1, 2, 3, 4, 5};
    std::array<int, 5> data = {1, 2, 3, 4, 5};

    int input;
    std::cin >> input;
    // data.push_back(input);

    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << std::endl;
    }

    for (auto d : data) {
        std::cout << d << " ";
    }
    std::cout << "\n";
    return 0;
}