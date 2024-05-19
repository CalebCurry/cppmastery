#include <iostream>
#include <ostream>
#include <vector>

class Point {
   protected:
    int x, y;

   public:
    Point(int x, int y) : x(x), y(y) {}

    virtual ~Point() {}

    virtual void print(std::ostream& os) const {
        os << "(" << x << ", " << y << ")";
    }

    // uses virtual print so only needed in base class
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        p.print(os);
        return os;
    }
};

class PointXYZ : public Point {
   private:
    int z;

   public:
    PointXYZ(int x, int y, int z) : Point(x, y), z(z) {}

    void print(std::ostream& os) const override {
        os << "(" << x << ", " << y << ", " << z << ")";
    }

    void XYZOnly() { std::cout << "This requires XYZ instance" << std::endl; }
};

void processPoint(Point* p) {
    auto result = dynamic_cast<PointXYZ*>(p);
    if (result != nullptr) {
        result->XYZOnly();
    }
}

int main() {
    PointXYZ pxyz = PointXYZ(50, 10, 30);
    Point p = Point(50, 10);
    std::vector<Point*> points{&pxyz, &p};

    for (auto p : points) {
        std::cout << *p << std::endl;
        processPoint(p);
    }
}