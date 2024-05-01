#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file " << inputFileName << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file " << outputFileName << std::endl;
        return 1;
    }

    std::vector<int> data;
    double number;
    while (inputFile >> number) {
        data.push_back(number);
    }

    double sum = 0;
    for (auto d : data) {
        sum += d;
    }

    double average = data.empty() ? 0 : sum / data.size();

    outputFile << "The average is: " << average << std::endl;
    std::cout << "The average is: " << average << std::endl;

    inputFile.close();
    outputFile.close();
}