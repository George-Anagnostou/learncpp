#include <iostream>
#include <limits>

int main() {
	int age {};

	while (true) {
		std::cout << "Enter your age: ";
		std::cin >> age;

		if (std::cin.fail()) { // no extraction took place
			std::cin.clear(); // reset state back to goodbit to use ignore()
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear bad input from stream
			continue; // try again
		}

		// clear partially valid input (e.g. 123abc456)
		// 123 is valid, fails at a, then abc456 is left as garbage without setting failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.gcount() > 1) { // if cleared out more than \n character
			continue;
		}

		if (age <= 0) { // make sure age is positive
			continue;
		}
		
		break;
	}

	std::cout << "" << age << '\n';

	return 0;
}
