#include <iostream>
#include <list>
#include <vector>

int main() {
    std::list<int> data = {1, 2, 3, 4, 5};

    for (auto it = data.begin(); it != data.end();) {
        *it *= 2;
        it++;
        if (it != data.end()) {
            it++;
        }
    }
    for (auto d : data) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    bool skip = false;
    for (auto &d : data) {
        if (skip) {
            skip = !skip;
            continue;
        }
        skip = !skip;
        d *= 2;
    }

    for (auto d : data) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}