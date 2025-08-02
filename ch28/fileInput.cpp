#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream inf { "sample.txt" };
	
	if (!inf) {
		std::cerr << "Error: unable to open sample.txt for reading\n";
		return 1;
	}

	std::string strInput {};
	// while (inf >> strInput) {
	// 	std::cout << strInput << '\n';
	// }
	while (std::getline(inf, strInput)) {
		std::cout << strInput << '\n';
	}

	return 0;
}
