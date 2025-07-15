#include <cassert>
#include <cstdint> // for fixed width integers
#include <iostream>

class FixedPoint2 {
private:
	std::int16_t m_base {};
	std::int8_t m_decimal {};

public:
	FixedPoint2(std::int16_t base=0, std::int8_t decimal=0)
	: m_base { base }
	, m_decimal { decimal }
	{
		// if either the base of decimal are negative, the number should be negative
		if (m_base < 0 || m_decimal < 0) {
			if (m_base > 0) {
				m_base = -m_base;
			}
			if (m_decimal > 0) {
				m_decimal = -m_decimal;
			}
		}
		m_base += m_decimal / 100;
		m_decimal = m_decimal % 100;
	}

	FixedPoint2(double dbl) :
		FixedPoint2(
			static_cast<std::int16_t>(std::trunc(dbl)),
			static_cast<std::int8_t>(std::round(dbl * 100) - std::trunc(dbl) * 100)
		)
	{}

	explicit operator double() const {
		return m_base + (static_cast<double>(m_decimal) / 100);
	}

	friend bool operator==(const FixedPoint2 f1, const FixedPoint2 f2);

	friend std::istream& operator>>(std::istream& in, FixedPoint2& f);

	FixedPoint2 operator-() const;

	friend FixedPoint2 operator+(const FixedPoint2 f1, const FixedPoint2 f2);

	friend bool testDecimal(const FixedPoint2& fp);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp) {
	out << static_cast<double>(fp);
	return out;
}

bool operator==(FixedPoint2 f1, FixedPoint2 f2) {
	return f1.m_base == f2.m_base && f1.m_decimal == f2.m_decimal;
}

std::istream& operator>>(std::istream& in, FixedPoint2& f) {
	double input {};
	in >> input;
	f = FixedPoint2{input};
	return in;
}

FixedPoint2 FixedPoint2::operator-() const {
	return FixedPoint2 { -static_cast<double>(*this) };
}

FixedPoint2 operator+(const FixedPoint2 f1, const FixedPoint2 f2) {
	return FixedPoint2 { static_cast<double>(f1) + static_cast<double>(f2) };
}

bool testDecimal(const FixedPoint2& fp) {
	if (fp.m_base >= 0) {
		return fp.m_decimal >= 0 && fp.m_decimal < 100;
	} else {
		return fp.m_decimal <= 0 && fp.m_decimal > -100;
	}
}

int main()
{
	// from step 2
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b{ -2, 8 };
	assert(static_cast<double>(b) == -2.08);

	FixedPoint2 c{ 2, -8 };
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d{ -2, -8 };
	assert(static_cast<double>(d) == -2.08);

	FixedPoint2 e{ 0, -5 };
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f{ 0, 10 };
	assert(static_cast<double>(f) == 0.1);

	// from step 3
	FixedPoint2 a3 { 1, 104 };
	std::cout << a3 << '\n';
	std::cout << static_cast<double>(a3) << '\n';
	assert(static_cast<double>(a3) == 2.04);
	assert(testDecimal(a3));

	FixedPoint2 b3 { 1, -104 };
	assert(static_cast<double>(b3) == -2.04);
	assert(testDecimal(b));

	FixedPoint2 c3 { -1, 104 };
	assert(static_cast<double>(c3) == -2.04);
	assert(testDecimal(c3));

	FixedPoint2 d3 { -1, -104 };
	assert(static_cast<double>(d3) == -2.04);
	assert(testDecimal(d3));

	// from step 4
	FixedPoint2 a4 { 0.01 };
	assert(static_cast<double>(a4) == 0.01);

	FixedPoint2 b4 { -0.01 };
	assert(static_cast<double>(b4) == -0.01);

	FixedPoint2 c4 { 1.9 };
	assert(static_cast<double>(c4) == 1.9);

	FixedPoint2 d4 { 5.01 };
	assert(static_cast<double>(d4) == 5.01);

	FixedPoint2 e4 { -5.01 };
	assert(static_cast<double>(e4) == -5.01);

	FixedPoint2 f4 { 106.9978 };
	assert(static_cast<double>(f4) == 107.00);

	FixedPoint2 g4 { -106.9978 };
	assert(static_cast<double>(g4) == -107.0);

	// step 5
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a5{ -0.48 };
	assert(static_cast<double>(a5) == -0.48);
	assert(static_cast<double>(-a5) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a5;
	std::cout << "You entered: " << a5 << '\n';
	assert(static_cast<double>(a5) == 5.68);

	return 0;
}
