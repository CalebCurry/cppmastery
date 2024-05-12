#include "lib/LinkedList.h"
#include "lib/Point.h"

// compile multifile with something like this:
// g++-13 -Wall -Wextra linked-list.cpp -o linked-list lib/*.cpp --std=c++23

int main() {
    CGL::LinkedList<CGL::Point> list;

    list.push(CGL::Point{5, 10});
    list.push(CGL::Point{50, 100});
    list.push(CGL::Point{500, 1000});

    std::cout << list << std::endl;
    std::cout << list.pop() << std::endl;
}