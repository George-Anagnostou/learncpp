#include <iostream>
#include <fstream>

int main() {
	std::ofstream outf { "sample.txt", std::ios::app }; // to append
	//
	if (!outf) {
		std::cerr << "Error: could not append to sample.txt\n";
		return 1;
	}

	outf << "This is line 3\n";
	outf << "This is line 4\n";

	return 0;
}
