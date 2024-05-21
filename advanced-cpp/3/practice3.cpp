#include <fstream>
#include <iostream>

void readFile(std::string fileName) {
    if (std::ifstream file(fileName); file.is_open()) {
        std::cout << file.rdbuf() << std::endl;
    } else {
        std::cout << "Error reading file" << std::endl;
    }
}

int main() { readFile("example.txt"); }