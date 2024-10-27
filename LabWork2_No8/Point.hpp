#include "LabWork2_No8.h"

class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {}

    double distance() const {
        return sqrt(x * x + y * y);
    }

    bool operator<(const Point& other) const {
        return this->distance() < other.distance();
    }

    bool operator==(const Point& other) const {
        return this->x == other.x && this->y == other.y;
    }
};

void printPoints(const std::list<Point>& points) {
    for (const auto& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }
}