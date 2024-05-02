// #include <bitset>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    try {
        std::ifstream inputFile(inputFileName);
        std::ofstream outputFile(outputFileName);

        inputFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        outputFile.exceptions(std::ofstream::badbit | std::ifstream::failbit);

        // std::cout << std::bitset<4>(std::ifstream::badbit) << std::endl;
        // std::cout << std::bitset<4>(std::ifstream::failbit) << std::endl;
        // std::cout << std::bitset<4>(std::ifstream::badbit |
        // std::ifstream::failbit)
        //           << std::endl;

        std::vector<int> data;
        double number;
        try {
            while (inputFile >> number) {
                data.push_back(number);
            }
        } catch (const std::ios_base::failure& e) {
            if (!inputFile.eof()) {
                throw;
            }
            inputFile.clear();
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
    } catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Something went wrong: " << e.what() << std::endl;
        return 2;
    } catch (...) {
        std::cerr << "Something went wrong" << std::endl;
    }
}