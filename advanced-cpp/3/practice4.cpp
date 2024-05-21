#include <fstream>
#include <iostream>
#include <vector>

int main() {
    double average;

    if (std::ifstream inputFile("input.txt"); inputFile.is_open()) {
        std::vector<int> data;
        double number;
        while (inputFile >> number) {
            data.push_back(number);
        }

        double sum = 0;
        for (auto d : data) {
            sum += d;
        }

        average = data.empty() ? 0 : sum / data.size();

    } else {
        std::cerr << "Unable to open input file" << std::endl;
        return 1;
    }

    if (std::ofstream outputFile("output.txt"); outputFile.is_open()) {
        outputFile << "The average is: " << average << std::endl;
    } else {
        std::cerr << "Unable to open output file" << std::endl;
        return 1;
    }

    std::cout << "The average is: " << average << std::endl;
}