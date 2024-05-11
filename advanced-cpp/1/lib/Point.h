#include <ostream>
#ifndef POINT_H
#define POINT_H

class Point {
   public:
    int x;
    int y;

    Point(int y, int x) : x(x), y(y) {}

    void print();

    friend std::ostream& operator<<(std::ostream& os, const Point p);
};

#endif