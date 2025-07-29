#include <iostream>

class Point {
private:
	int m_x {};
	int m_y {};

public:
	Point(int x, int y)
	: m_x { x }
	, m_y { y }
	{}

	friend std::ostream& operator<<(std::ostream& out, const Point& p) {
		out << "Point(" << p.m_x << ", " << p.m_y << ')';
		return out;
	}
};

class Shape {
public:
	virtual std::ostream& print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Shape& shape) {
		return shape.print(out);
	}
	virtual ~Shape() = default;
};

class Triangle : public Shape {
private:
	Point m_point_x;
	Point m_point_y;
	Point m_point_z;

public:
	Triangle(const Point& x, const Point& y, const Point& z)
	: m_point_x { x }
	, m_point_y { y }
	, m_point_z { z }
	{}

	std::ostream& print(std::ostream& out) const override {
		out << "Triangle(" << m_point_x << ", " << m_point_y << ", " << m_point_z << ')';
		return out;
	}
};

class Circle : public Shape {
private:
	Point m_center;
	int m_radius {};

public:
	Circle(const Point& point, int radius)
	: m_center { point }
	, m_radius { radius }
	{}

	std::ostream& print(std::ostream& out) const override {
		out << "Circle(" << m_center << ", radius " << m_radius << ')';
		return out;
	}

	int getRadius() const { return m_radius; }
};

int getLargestRadius(const std::vector<Shape*>& v) {
	int largestRadius { 0 };
	for (const auto* shape : v) {
		if (auto* circle { dynamic_cast<const Circle*>(shape) }) {
			largestRadius = std::max(largestRadius,  circle->getRadius());
		}
	}
	return largestRadius;
}

int main() {
	std::vector<Shape*> v {
		new Circle { Point { 1, 2 }, 7 },
		new Triangle { Point { 1, 2 }, Point { 3, 4 }, Point { 5, 6 }},
		new Circle { Point { 7, 8 }, 3 },
	};

	// print each shape in vector on its own line
	for (const auto* shape : v) {
		std::cout << *shape << '\n';
	}
	

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

	// delete each element in vector
	for (const auto* shape : v) {
		delete shape;
	}

	return 0;
}
