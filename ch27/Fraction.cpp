#include <iostream>
#include <stdexcept> // for std::runtime_error
#include <exception> // for std::exception

class Fraction {
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator=0, int denominator=1)
	: m_numerator { numerator }
	, m_denominator { denominator }
	{
		if (denominator == 0) {
			throw std::runtime_error("Invalid denominator");
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
	out << f.m_numerator << '/' << f.m_denominator;
	return out;
}

int main() {
	std::cout << "Enter the numerator: ";
	int numerator {};
	std::cin >> numerator;

	std::cout << "Enter the denominator: ";
	int denominator {};
	std::cin >> denominator;

	try {
		Fraction f { numerator, denominator };
		std::cout << f << '\n';
	} catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}
