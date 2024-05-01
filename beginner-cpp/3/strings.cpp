#include <format>
#include <iostream>
#include <sstream>
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

    std::string name = "Caleb";
    std::string last = "Curry";

    std::string full = name + " " + last;
    // name.append(" ").append(last);

    std::cout << full << std::endl;

    int hour = 6;
    int min = 20;
    int sec = 37;
    int micro = 343434;

    std::string result =
        std::format("time is {}:{}:{}.{}", hour, min, sec, micro);
    std::cout << result << std::endl;

    std::ostringstream stream;
    stream << "time is " << hour << ":" << min << ":" << sec << "." << micro;
    std::string result2 = stream.str();
    std::cout << result2 << std::endl;
}