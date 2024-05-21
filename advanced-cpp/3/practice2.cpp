#include <iostream>
#include <optional>

std::optional<int> getValue() {
    bool success = false;

    if (success) {
        return 43;
    } else {
        return std::nullopt;
    }
}

int main() {
    switch (auto value = getValue(); value.has_value() ? 1 : -1) {
        case 1:
            std::cout << *value << std::endl;
            break;
        case -1:
            std::cout << "No value provided" << std::endl;
            break;
    }

    // if (auto value = getValue(); value.has_value()) {
    //     std::cout << *value << " was returned." << std::endl;
    // } else {
    //     std::cout << "No value returned" << std::endl;
    // }
}