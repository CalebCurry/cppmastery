#include <iostream>
#include <vector>

void doubleData(std::vector<int>& vec) {
    for (int& element : vec) {
        element *= 2;
    }
}

void printData(const std::vector<int>& data) {
    for (const int& element : data) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> myData = {1, 2, 3, 4, 5};
    doubleData(myData);
    printData(myData);

    return 0;
}