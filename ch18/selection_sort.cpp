#include <iostream>
#include <iterator>
#include <utility>

int main() {
	int array[] { 30, 50, 20, 10, 40 };
	constexpr int length { static_cast<int>(std::size(array)) };

	// step through each element of the array
	// (exepct the last one, which will already be sorted by the time we get there)
	for (int startIndex{0}; startIndex < length - 1; ++startIndex) {
		// smallestIndex is hte index of the smallest element we've encountered this iteration
		// start by assuming the smallest element is the first element of this iteration
		int smallestIndex { startIndex } ;

		// then look for a smaller element in the rest of the array
		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex) {
			// if we've found an alement that is smaller than the prev smallest
			if (array[currentIndex] < array[smallestIndex]) {
				smallestIndex = currentIndex;
			}
		}

		// smallestIndex is now the index of the smallest element in the remaining array

		// swap our start element with the smallest element
		std::swap(array[startIndex], array[smallestIndex]);
	}
	// now that the array is sorted, print out the sorted array
	for (int index { 0 }; index < length; ++index) {
		std::cout << array[index] << ' ';
	}

	std::cout << '\n';

	return 0;
}
