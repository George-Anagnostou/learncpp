#include <iostream>
#include <array>

/*
void printLength(const std::array<int, 5> &arr) {
	constexpr int length { std::size(arr) }; // compile error?
						 // passing by const reference means
						 // this returns a non-constexpr value
						 // P2280
	std::cout << "length: " << length << '\n';
}
*/

int main() {
	std::array<double, 365> highTemp {};

	constexpr std::array<char, 5> hello { 'h', 'e', 'l', 'l', 'o' };
	std::cout << hello[1] << '\n';

	std::array arr { 9, 7, 5, 3, 1 };
	constexpr int length { std::size(arr) }; // works fine
	std::cout << "length: " << length << '\n';

	/*printLength(arr);*/



	constexpr std::array prime { 2, 3, 5, 7, 11 };

	// std::get() behaves like std::array.at(), but does compile time checks,
	// not just runtime
	std::cout << std::get<3>(prime) << '\n';
	// std::cout << std::get<9>(prime); // invalid index (compile error)


	// 17.2 quiz 1
	std::cout << hello[1];
	std::cout << hello.at(1);
	std::cout << std::get<1>(hello);

	return 0;
}
