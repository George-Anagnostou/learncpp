#include <iostream>
#include <string>

int main() {
	try {
		throw -1; // trivial example
	} catch (double) {
		std::cerr << "Caught exception of type `double`\n";
	} catch (int x) {
		std::cerr << "Caught exception of type `int` with value: " << x << '\n';
	} catch (const std::string&) {
		std::cerr << "Caught exception of type `std::string`\n";
	}

	std::cout << "Continuing on our merry way\n";

	return 0;
}
