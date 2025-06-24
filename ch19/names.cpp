#include <algorithm>
#include <iostream>

std::size_t getNameCount() {
	std::cout << "How many names would you like to enter? ";
	std::size_t num {};
	std::cin >> num;

	return num;
}

std::string getName(int num) {
	std::cout << "Enter name #" << num + 1 << ": ";
	std::string name {};
	std::getline(std::cin >> std::ws, name);
	return name;
}

int main() {
	std::size_t num { getNameCount() };

	std::string* nameArray { new std::string[num]{} };

	for (std::size_t i { 0 }; i < num; ++i) {
		std::string name { getName(i) };
		nameArray[i] = name;
	}

	std::sort(nameArray, nameArray + num);

	std::cout << "Here is your sorted list: \n";
	for (std::size_t i { 0 }; i < num; ++i) {
		std::cout << "Name #" << i + 1 << ": " << nameArray[i] << '\n';
	}

	delete[] nameArray;

	return 0;
}
