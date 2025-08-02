#include <fstream>
#include <iostream>

int main() {
	std::ofstream outf { "sample.txt" };

	if (!outf) {
		std::cerr << "Error: sample.txt would not be opened for writing\n";
		return 1;
	}

	outf << "This is line 1\n";
	outf << "This is line 2\n";

	return 0;
}
