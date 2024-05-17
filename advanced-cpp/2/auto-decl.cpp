#include <iostream>
#include <vector>

class Point {
   public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
};

template <typename T, typename U>
auto add(T x, U y) {
    return x + y;
}

auto calculate(double x, double y) -> decltype(5 / 3) { return x * y; }

int main() {
    // auto x = calculate(4, 3);
    // decltype(calculate(5.5, 3.3)) y = 10;

    // auto z = add(10, 5.5);
    // std::cout << z << std::endl;

    Point p1(5, 10);
    Point p2(30, 30);

    Point result = add(p1, p2);

    std::cout << result.x << " " << result.y << std::endl;

    // std::vector<double> data{5, 10, 15};

    // for (auto d : data) {
    //     std::cout << d << std::endl;
    // }
}