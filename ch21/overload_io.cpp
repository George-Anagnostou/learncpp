#include <iostream>

class Point {
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point(double x=0.0, double y=0.0, double z=0.0)
	: m_x{x}, m_y{y}, m_z{z} {}

	Point operator+() const;

	friend std::ostream& operator<<(std::ostream& out, const Point& point);
	friend std::istream& operator>>(std::istream& in, Point& point);
};

Point Point::operator+() const {
	return { m_x, m_y, m_z };
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
	return out;
}

/* issues with partial extrations
std::istream& operator>>(std::istream& in, Point& point) {
	in >> point.m_x >> point.m_y >> point.m_z;
	return in;
}
*/

/* allows for transactional operation
all or nothing extration for a Point, but issues with default behavior
being different from operator>> on fundemental types
std::istream& operator>>(std::istream& in, Point& point) {
	double x {};
	double y {};
	double z {};

	if (in >> x >> y >> z) {
		point = Point { x, y, z };
	}

	return in;
}
*/

std::istream& operator>>(std::istream& in, Point& point) {
	double x {};
	double y {};
	double z {};

	in >> x >> y >> z;
	point = in ? Point { x, y, z } : Point{};

	return in;
}

int main() {
	std::cout << "Enter a point: ";

	Point point1 { 1.0, 2.0, 3.0 }; // non-zero test data
	std::cin >> point1;

	std::cout << "You entered: " << point1 << '\n';

	return 0;
}
