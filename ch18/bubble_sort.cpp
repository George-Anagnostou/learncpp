#include <array>
#include <iostream>

int main() {
	int array[] { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length { static_cast<int>(std::size(array)) };

	// sort array
	for ( int i { 0 }; i < length - 1; ++i) {
		int endOfArrayIndex { length - i };
		bool swapped { false };

		for (int j { 0 }; j < endOfArrayIndex - 1; ++j) {
			if (array[j] > array[j+1]) {
				std::swap(array[j], array[j+1]);
				swapped = true;
			}
		}
		if (!swapped) {
			std::cout << "Early termination on interation " << i+1 << '\n';
			break;
		}
	}

	// print array
	for (int i { 0 }; i < length; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}
