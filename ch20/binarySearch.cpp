#include <iostream>
#include <iterator>

int binarySearch(const int* array, int target, int min, int max) {
	while (min <= max) {
		int midpoint { min + ((max - min) / 2) };
		if (array[midpoint] == target) {
			return midpoint;
		} else if (array[midpoint] > target) {
			max = midpoint - 1;
		} else {
			min = midpoint + 1;
		}
	}
	return -1;
}

int binarySearchRecursive(const int* array, int target, int min, int max) {
	if (min > max) {
		return -1;
	}

	int midpoint { min + ((max - min) / 2) };

	if (array[midpoint] > target) {
		return binarySearchRecursive(array, target, min, midpoint - 1);
	} else if (array[midpoint] < target) {
		return binarySearchRecursive(array, target, midpoint + 1, max);
	}

	return midpoint;
}

int main() {
	constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// Here are the test values
	constexpr int testValues[]{ 0, 3, 12, 13, 22, 26, 43, 44, 48, 49 };

	// And here are the results that we expect for those test values
	int expectedResult[]{ -1, 0, 3, -1, -1, 8, -1, 13, 14, -1 };
	static_assert(std::size(testValues) == std::size(expectedResult));

	int numTestValues { std::size(testValues) };
	for (int count { 0 }; count < numTestValues; ++count) {
		int index { binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };

		if (index == expectedResult[count]) {
			std::cout << "test value " << testValues[count] << " passed!\n";
		} else {
			std::cout << "test value " << testValues[count] << " failed\n";
		}
	}

	for (int count { 0 }; count < numTestValues; ++count) {
		int index { binarySearchRecursive(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };

		if (index == expectedResult[count]) {
			std::cout << "test value " << testValues[count] << " passed!\n";
		} else {
			std::cout << "test value " << testValues[count] << " failed\n";
		}
	}

	return 0;
}
