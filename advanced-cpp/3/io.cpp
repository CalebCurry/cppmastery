#include <fstream>
#include <iostream>
#include <vector>

class IO {
   public:
    std::ifstream input;
    std::ofstream output;

    IO() {
        std::cout << "Opening files" << std::endl;
        input = std::ifstream("input.txt");
        output = std::ofstream("output.txt");
    }

    bool isOpen() { return input.is_open() && output.is_open(); }

    ~IO() { std::cout << "closing files" << std::endl; }
};

int main() {
    if (IO io; io.isOpen()) {
        std::vector<int> data;
        double number;
        while (io.input >> number) {
            data.push_back(number);
        }

        double sum = 0;
        for (auto d : data) {
            sum += d;
        }

        double average = data.empty() ? 0 : sum / data.size();
        io.output << "The average is: " << average << std::endl;
        std::cout << "The average is: " << average << std::endl;
    }
}