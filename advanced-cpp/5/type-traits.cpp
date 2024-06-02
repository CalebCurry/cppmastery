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

// template <typename T, typename U>
// auto add(T x, U y) {
//     if constexpr (std::is_pointer<T>() && std::is_pointer<U>()) {
//         return *x + *y;
//     } else if constexpr (std::is_pointer<T>()) {
//         return *x + y;
//     } else if constexpr (std::is_pointer<U>()) {
//         return x + *y;
//     } else {
//         return x + y;
//     }
// }

// entire function for pointers
template <
    typename T, typename U,
    std::enable_if_t<std::is_pointer<T>() && std::is_pointer<U>(), int> = 0>
auto add(const T& x, const U& y) {
    return *x + *y;
}

// integers or other stuff
template <typename T, typename U,
          std::enable_if<!std::is_pointer<T>() && !std::is_pointer<U>(),
                         int>::type = 0>
auto add(const T& x, const U& y) {
    return x + y;
}

template <typename T, typename U,
          std::enable_if<std::is_pointer<T>() && !std::is_pointer<U>(),
                         int>::type = 0>
auto add(const T& x, const U& y) {
    return *x + y;
}

template <typename T, typename U,
          std::enable_if<!std::is_pointer<T>() && std::is_pointer<U>(),
                         int>::type = 0>
auto add(const T& x, const U& y) {
    return x + *y;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << add(a, b) << std::endl;

    int* ap = &a;
    int* bp = &b;
    // std::cout << add(ap, 1) << std::endl;
    std::cout << add(ap, bp) << std::endl;
    std::cout << add(ap, b) << std::endl;
    std::cout << add(a, bp) << std::endl;

    Point p1(5, 10);
    Point p2(50, 10);
    Point p3 = add(p1, p2);
    std::cout << p3.x << " " << p3.y << std::endl;
}