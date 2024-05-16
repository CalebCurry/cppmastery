import <iostream>;

#include "lib/LinkedList.h"
import Point;

int main() {
    CGL::LinkedList<CGL::Point> list;

    list.push(CGL::Point{5, 10});
    list.push(CGL::Point{50, 100});
    list.push(CGL::Point{500, 1000});

    std::cout << list << std::endl;
    std::cout << list.pop() << std::endl;
}