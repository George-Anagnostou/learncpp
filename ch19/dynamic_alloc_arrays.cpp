#include <cstddef>
#include <iostream>

int main() {
	std::cout << "Enter a positive integer: ";
	std::size_t length{};
	std::cin >> length;

	int* array { new int[length]{} }; // use array new. length does not need to be constant!
	
	std::cout << "I just allocated an array of integers of length: " << length << '\n';

	array[0] = 5;
	delete[] array;

	return 0;
}
