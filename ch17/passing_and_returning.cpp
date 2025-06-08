#include <array>
#include <iostream>
#include <limits>

void passByRef(const std::array<int, 5>& arr) { // explicitly specify <int, 5> as part of type
	std::cout << arr[0] << '\n';
}

// function template to make generic both the type and size of an array
template <typename T, std::size_t N>
void passByRef(const std::array<T, N>& arr) {
	static_assert(N != 0); // fail if zero-length array
	std::cout << arr[0] << '\n';
}

// can also create a function template for only one parameter
template <std::size_t N> // note only length has been tempalted
void passByRef(const std::array<int, N>& arr) {
	static_assert(N != 0);
	std::cout << arr[0] << '\n';
}

// can also make these `auto`
// template <typename T, auto N>

template <typename T, std::size_t N>
void LrintElement3(const std::array<T, N>& arr) {
	// std::cout << arr[3] << '\n'; // this is a bug
				     // what if N = 2? 
				     // no compile-time bounds checking
	
	// this should instead be...
	std::cout << std::get<3>(arr) << '\n'; // since std::get() is valid at compile time
}

// return by value
template <typename T, std::size_t N>
std::array<T, N> inputArray() {
	std::array<T, N> arr{};
	std::size_t index { 0 };
	while (index < N) {
		std::cout << "Enter value #" << index << ": ";
		std::cin >> arr[index];

		if (!std::cin) {
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		++index;
	}

	return arr;
}

// return by out-parameter (not value)
template <typename T, std::size_t N>
void inputArray(std::array<T, N>& arr) { // pass by non-const reference
	std::size_t index { 0 };
	while (index < N) {
		std::cout << "Enter value #" << index << ": ";
		std::cin >> arr[index];

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		++index;
	}
}

int main() {
	std::array arr { 9, 7, 5, 3, 1 };
	passByRef(arr);

	std::array arr2 { 1.2, 3.4, 5.6, 7.8, 9.9 };
	passByRef(arr2);

	// return by value
	std::array<int, 5> arr3 { inputArray<int, 5>() };
	std::cout << "The value of element 2 is " << arr3[2] << '\n';

	// return by out-parameter
	std::array<int, 5> arr4 {};
	inputArray(arr4);
	std::cout << "The value of element 2 is " << arr[2] << '\n';

	return 0;
}
