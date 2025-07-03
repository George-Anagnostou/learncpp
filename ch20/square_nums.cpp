#include "Random.h"
#include <algorithm>
#include <iostream>
#include <vector>

int getNumber() {
	std::cout << "Enter an integer: ";
	int num {};
	std::cin >> num;
	return num;
}

int generateMultiplier() {
	return Random::get(2, 4);
}

int getGuess() {
	std::cout << ">> ";
	int num {};
	std::cin >> num;
	return num;
}

bool findAndRemove(std::vector<int>& numbers, int guess) {
	auto found { std::find(numbers.begin(), numbers.end(), guess) };

	if (found == numbers.end()) {
		return false;
	}

	numbers.erase(found);
	return true;
}

int findClosestNumber(const std::vector<int>& numbers, int guess) {
	return *std::min_element(numbers.begin(), numbers.end(),
		  	[=](int a, int b) {
				return std::abs(a - guess) < std::abs(b - guess);
			});
}

void printSuccess(const std::vector<int>& numbers) {
	std::cout << "Nice! ";
	if (numbers.size() == 0) {
		std::cout << "You found all the numbers, good job!\n";
	} else {
		std::cout << numbers.size() << " number(s) left.\n";
	}
}

void printFailure(const std::vector<int>& numbers, int guess) {
	int closest { findClosestNumber(numbers, guess) };

	std::cout << guess << " is wrong!\n";

	std::cout << "Try " << closest << " next time.\n";
}

int main() {
	int multiplier { generateMultiplier() };

	std::cout << "Where to start?\n";
	int startNumber { getNumber() };

	std::cout << "How many?\n";
	int numValues { getNumber() };

	std::vector<int> arr(static_cast<std::size_t>(numValues));
	for (int i = 0; i < numValues; ++i) {
		arr[i] = (startNumber + i) * (startNumber + i) * multiplier;
	}

	std::cout << "I generated " << numValues << " square numbers. Do you know what each number is after multiplying it by " << multiplier << " ?\n";

	while (true) {
		int guess { getGuess() };

		if (!findAndRemove(arr, guess)) {
			printFailure(arr, guess);
			break;
		}

		printSuccess(arr);
		if (arr.size() == 0) {
			break;
		}
	}

	return 0;
}
