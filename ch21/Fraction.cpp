#include <numeric>
#include <iostream>

class Fraction {
private:
	int m_numerator { 0 };
	int m_denomenator { 1 };

public:
	explicit Fraction(int numerator, int denomenator=1)
		: m_numerator { numerator }
		, m_denomenator { denomenator }
		{
			reduce();
		}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int x);
	friend Fraction operator*(int x, const Fraction& f1);

	void reduce() {
		int gcd { std::gcd(m_numerator, m_denomenator) };
		m_numerator /= gcd;
		m_denomenator /= gcd;
	}

	void print() const { 
		std::cout << m_numerator << '/' << m_denomenator << '\n'; 
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	return Fraction { f1.m_numerator * f2.m_numerator, f1.m_denomenator * f2.m_denomenator };
}

Fraction operator*(const Fraction& f1, int x) {
	return Fraction { f1.m_numerator * x, f1.m_denomenator };
}

Fraction operator*(int x, const Fraction& f1) {
	return Fraction { f1 * x };
}

int main() {
	Fraction f1{2, 5};
	f1.print();

	Fraction f2{3, 8};
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
	f6.print();

	Fraction f7 { 0, 6 };
	f7.print();

	return 0;
}
