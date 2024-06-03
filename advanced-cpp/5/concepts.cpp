#include <concepts>
#include <iostream>
#include <type_traits>

class Point {
   public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(this->x + other.x, this->y + other.y);
    }
};

template <typename T>
concept Pointer = std::is_pointer_v<T>;

template <typename T>
concept NonPointer = !std::is_pointer_v<T>;

template <typename T>
concept Numeric = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <typename T>
concept Custom = Numeric<T> && std::is_signed_v<T>;

// template <Custom T, typename U>
// auto add(const T& x, const U& y) {
//     return x + y;
// }

template <Pointer T, Pointer U>
auto add(const T& x, const U& y) {
    return *x + *y;
}

template <NonPointer T, NonPointer U>
auto add(const T& x, const U& y) {
    return x + y;
}

template <Pointer T, NonPointer U>
auto add(const T& x, const U& y) {
    return *x + y;
}

template <NonPointer T, Pointer U>
auto add(const T& x, const U& y) {
    return x + *y;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << add(a, b) << std::endl;

    int* ap = &a;
    int* bp = &b;
    std::cout << add(ap, 1) << std::endl;
    std::cout << add(ap, bp) << std::endl;
    std::cout << add(ap, b) << std::endl;
    std::cout << add(a, bp) << std::endl;

    Point p1(5, 10);
    Point p2(50, 10);
    // Point p3 = add(p1, p2);
    // std::cout << p3.x << " " << p3.y << std::endl;
}