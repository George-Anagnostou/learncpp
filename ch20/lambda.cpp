#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main() {
	constexpr std::array<std::string_view, 4> arr { "apple", "banana", "walnut", "lemon" };

	// define function where we use it
	auto found { std::find_if(arr.begin(), arr.end(),
			   [](std::string_view str) { // define lambda
			   	return str.find("nut") != std::string_view::npos;
			   })};

	if (found == arr.end()) {
		std::cout << "No nuts\n";
	} else {
		std::cout << "Found " << *found << '\n';
	}

	return 0;
}
