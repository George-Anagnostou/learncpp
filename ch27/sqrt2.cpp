#include <cmath> // for sqrt()
#include <iostream>

// modular square root function
double mySqrt(double x) {
	if (x < 0.0) {
		throw "Can't take sqrt of negative number";
	}

	return std::sqrt(x);
}

int main() {
	std::cout << "Enter a number: ";
	double x {};
	std::cin >> x;

	try {
		double d = mySqrt(x);
		std::cout << "The sqrt of " << x << " is " << d << '\n';
	} catch (const char* exception) {
		std::cerr << "Error: " << exception << std::endl;
	}

	return 0;
}
