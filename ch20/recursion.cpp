#include <iostream>

int factorial(int n) {
	if (n <= 0) {
		return 1;
	}
	return factorial(n - 1) * n;
}

int sumDigits(int n) {
	if (n < 10) {
		return n;
	}

	return sumDigits(n / 10) + n % 10;
}

void printBinary(int n) {
	if (n == 0) {
		return;
	}

	printBinary(n / 2);

	std::cout << n % 2;
}

// same as printBinary, but also handles values <= 0
void printBinary2(unsigned int n) {
	if (n > 1) { // only recurse if n > 1
		printBinary2(n / 2);
	}

	std::cout << n % 2;
}

int main() {
	for (auto i { 0 }; i < 7; ++i) {
		std::cout << factorial(i) << '\n';
	}

	std::cout << sumDigits(93427) << '\n';

	printBinary(10);
	printBinary2(static_cast<unsigned int>(10));

	return 0;
}
