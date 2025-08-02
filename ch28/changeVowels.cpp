#include <fstream>
#include <iostream>

int main() {
	std::fstream iofile { "sample.txt", std::ios::in | std::ios::out };

	if (!iofile) {
		std::cerr << "Error: could not open sample.txt";
		return 1;
	}

	char chChar {};
	
	while (iofile.get(chChar)) {
		switch (chChar) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				iofile.seekg(-1, std::ios::cur);
				iofile << '#';
				iofile.seekg(iofile.tellg(), std::ios::beg);
				break;
		}
	}

	return 0;
}
