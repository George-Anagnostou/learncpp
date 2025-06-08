#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Animal {
	enum Type {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		maxAnimals,
	};

	struct Data {
		std::string_view name {};
		int numLegs {};
		std::string_view sound {};
	};

	using namespace std::string_view_literals; // for sv suffix
	constexpr std::array<Data, maxAnimals> animalData {
		Data { "chicken"sv, 2, "cluck" },
		Data { "dog"sv, 4, "bark" },
		Data { "cat"sv, 4, "meow" },
		Data { "elephant"sv, 4, "phffrrrtt" },
		Data { "duck"sv, 2, "quack" },
		Data { "snake"sv, 0, "hissss" },
	};

	constexpr std::array types {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
	};

	static_assert(std::size(types) == maxAnimals);
	static_assert(std::size(animalData) == maxAnimals);
}

void printAnimalData(Animal::Type animalType) {
	const Animal::Data& animal { Animal::animalData[animalType] };
	std::cout << "A " << animal.name 
		  << " has "
		  << animal.numLegs
		  << " and says "
		  << animal.sound << ".\n";
}

std::istream& operator>> (std::istream& in, Animal::Type& animal) {
	std::string input{};
	std::getline(in >> std::ws, input);

	for (std::size_t index = 0; index < Animal::animalData.size(); ++index) {
		if (input == Animal::animalData[index].name) {
			animal = static_cast<Animal::Type>(index);
			return in;
		}
	}

	in.setstate(std::ios_base::failbit);
	return in;
}

int main() {
	std::cout << "Enter an animal: ";
	Animal::Type type{};
	std::cin >> type;

	if (!std::cin) {
		std::cin.clear();
		std::cout << "That animal could not be found.\n";
		type = Animal::maxAnimals; // set to invalid option
	} else {
		printAnimalData(type);
	}

	std::cout << "\nHere is the data for the rest of the animals:\n";
	for (auto a : Animal::types) {
		if (a != type) {
			printAnimalData(a);
		}
	}

	return 0;
}
