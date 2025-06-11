#include <iostream>

int getInput() {
	std::cout << "Enter a single digit integer, or -1 to quit: ";
	int input {};
	std::cin >> input;
	return input;
}

int main() {
	// constexpr std::array<int, 3> a{};
	constexpr int a[3] {};

	constexpr int squares[4] { 0, 1, 4, 9 };
	int input { getInput() };

	if (input == -1) {
		std::cout << "Bye\n";
		return 0;
	}

	for (const auto& elm : squares) {
		if (input == elm) {
			std::cout << input << " is a perfect square\n";
			return 0;
		}
	}

	std::cout << input << " is not a perfect square\n";
	return 0;
}
