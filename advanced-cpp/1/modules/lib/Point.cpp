export module Point;
import <iostream>;
import <ostream>;

export namespace CGL {
class Point {
   public:
    int x;
    int y;

    Point(int y, int x) : x(x), y(y) {}

    void print() { std::cout << *this << std::endl; }

    friend std::ostream& operator<<(std::ostream& os, const Point p) {
        os << p.x << " " << p.y;
        return os;
    }
};
}  // namespace CGL
