#include <iostream>
#include <vector>

int main() {
    // std::string is a class/object in C++
    // std::string is not a primitive
    // primitives / core types -- int, double, bool, char[]
    // std::string --> an object
    // literal --> a value hardcoded in your code

    std::string message = "Don't tell anybody my password is pass123";
    std::cout << message[3] << std::endl;
    std::cout << message.at(22) << std::endl;

    auto result = message.find("password");

    if (result == std::string::npos) {
        std::cout << "String not found" << std::endl;
    } else {
        message.replace(result, 8, "********");
        std::cout << message << std::endl;
        auto c = message.c_str();  // if needed
    }
}