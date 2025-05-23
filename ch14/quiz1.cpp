#include <cmath>
#include <iostream>

class Point2d {
private:
    double m_x { 0.0 };
    double m_y { 0.0 };

public:
    Point2d() = default;
    Point2d(double x, double y)
        : m_x { x }
        , m_y { y } {}
        
    void print() const {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }
    
    double distanceTo(const Point2d& point) const {
        return std::sqrt(
            (m_x - point.m_x)*(m_x - point.m_x) +
            (m_y - point.m_y)*(m_y - point.m_y));
    }
};

int main() {
    Point2d first{};
    Point2d second { 3.0, 4.0 };

    // Point2d third { 4.0 }; // should error if uncommented

    first.print();
    second.print();
    
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}