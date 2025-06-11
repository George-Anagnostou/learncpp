#include <array>
#include <iostream>

void printArray(const int* begin, const int* end) {
	for (; begin != end; ++begin) { // iterate from begin up to (but excluding) end
		std::cout << *begin << ' '; // dereference loop variable to get current element
	}

	std::cout << '\n';
}

int main() {
	const int arr[] { 3, 2, 1 };

	std::cout << &arr[0] << ' ' << &arr[1] << ' ' << &arr[2] << '\n';
	std::cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';

	std::cout << arr << ' ' << (arr+ 1) << ' ' << (arr+ 2) << '\n';
	std::cout << *arr << ' ' << *(arr+ 1) << ' ' << *(arr+ 2) << '\n';


	constexpr int arr2[] { 9, 7, 5, 3, 1 };

	const int* begin { arr2 };			// begin points to start element
	const int* end { arr2 + std::size(arr2) };	// end points to one-past the end element

	printArray(begin, end);

	return 0;
}
