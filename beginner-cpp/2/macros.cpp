#include <iostream>

#define DEBUG 0

#if DEBUG == 1
#define println(message) std::cout << message << std::endl
#else
#define println(message)
#endif

bool debug = false;

template <typename T>
void log(const T& message) {
    if (debug) {
        std::cout << message << std::endl;
    }
}

int main() {
    log(5);
    log("Hello world");
}