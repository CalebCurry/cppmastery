#include "Point.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Point p) {
    os << p.x << " " << p.y;
    return os;
}

void Point::print() { std::cout << *this << std::endl; }
