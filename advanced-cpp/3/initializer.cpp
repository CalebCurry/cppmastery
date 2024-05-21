#include <iostream>

int runProgram() { return -1; }

int main() {
    for (int number; std::cin >> number && number >= 0;) {
        std::cout << "You entered: " << number << std::endl;
        std::cout << "Enter a negative number to exit the loop" << std::endl;
    }

    // the while way of doing it
    //  int number;

    // while (std::cin >> number && number >= 0) {
    //     std::cout << "You entered: " << number << std::endl;
    //     std::cout << "Enter a negative number to exit the loop" << std::endl;
    // }

    switch (auto result = runProgram(); result) {
        case 0:
            std::cout << "Program was a success" << std::endl;
            break;
        case 1:
        case 2:
        case 3:
            std::cout << "Data error" << std::endl;
            break;
        default:
            std::cout << "Something went wrong" << std::endl;
            break;
    }

    if (auto result = runProgram()) {
        std::cout << "The program failed with exit code " << result
                  << std::endl;
    }
}