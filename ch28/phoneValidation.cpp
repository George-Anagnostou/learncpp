#include <algorithm> // for std::equal
#include <cctype> // for std::isdigit, std::isspace, std::isalpha
#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <string_view>

bool inputMatches(std::string_view input, std::string_view pattern) {
	if (input.length() != pattern.length()) {
		return false;
	}

	// table defines special symbols that match range of user input
	// each symbol is mapped to a function that validates input for that symbol
	static const std::map<char, int (*)(int)> validators {
		{ '#', &std::isdigit },
		{ '_', &std::isspace },
		{ '@', &std::isalpha },
		{ '?', [](int) { return 1; } }
	};

	// C++20 for ranges
	return std::ranges::equal(input, pattern, [](char ch, char mask) -> bool {
		auto found { validators.find(mask) };
		if (found != validators.end()) {
			// the patern's element was found in validators
			// call corresponding function
			return (*found->second)(ch);
		}
		// patern's element was not found in validators
		// the characters have to be an exact match
		return ch == mask;
	});
}

int main() {
	std::string phoneNumber {};
	do {
		std::cout << "Enter a phone number (###) ###-####: ";
		std::getline(std::cin, phoneNumber);
	} while (!inputMatches(phoneNumber, "(###) ###-####"));

	std::cout << "You entered : " << phoneNumber << '\n';

	return 0;
}
