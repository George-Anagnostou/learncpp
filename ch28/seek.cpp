#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream inf { "sample.txt" };

	if (!inf) {
		std::cerr << "Error: sample.txt could not be opened\n";
		return 1;
	}

	std::string strData;

	inf.seekg(5); // move to 5th character
	std::getline(inf, strData);
	std::cout << strData << '\n';

	inf.seekg(8, std::ios::cur); // move 8 more bytes into file
	std::getline(inf, strData);
	std::cout << strData << '\n';

	inf.seekg(-14, std::ios::end);
	std::getline(inf, strData);
	std::cout << strData << '\n';

	return 0;
}
