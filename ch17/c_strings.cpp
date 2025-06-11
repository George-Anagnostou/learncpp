#include <array>
#include <cstring>
#include <iostream>

void printLetter(const char str[]) {
	while (*str != '\0') {
		std::cout << *str;
		++str;
	}
}

void printLetterReverse(const char str[]) {
	const char *ptr { str };

	while (*ptr != '\0') {
		++ptr;
	}

	while (ptr-- != str) {
		std::cout << *ptr;
	}

}

int main() {
	char str[] { "hello" };
	printLetter(str);

	std::cout << '\n';

	printLetterReverse(str);


	return 0;
}
