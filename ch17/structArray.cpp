#include <array>
#include <iostream>
#include <string_view>

struct House {
	int number{};
	int stories{};
	int roomsPerStory{};
};

struct Student {
	int id{};
	std::string_view name{};
};

constexpr std::array students {
	Student { 0, "Alex" },
	Student { 1, "Joe" },
	Student { 2, "Bob" },
};

const Student* findStudentById(int id) {
	for (auto& s : students) {
		if (s.id == id) return &s;
	}

	return nullptr;
}

int main() {

	/* Initialize array and assign elements
	std::array<House, 3> houses{};

	houses[0] = { 13, 1, 7 };
	houses[1] = { 14, 2, 5 };
	houses[2] = { 15, 2, 4 };
	*/

	// initialize array of structs
	constexpr std::array houses {
		House { 13, 1, 7 },
		House { 14, 2, 5 },
		House { 15, 2, 4 },
	};

	for (const auto& house : houses) {
		std::cout << "House number " << house.number
			  << " has " << (house.stories * house.roomsPerStory)
			  << " rooms.\n";
	}



	constexpr std::string_view nobody { "nobody" };
	const Student* s1 { findStudentById(1) };
	std::cout << "You found: " << (s1 ? s1->name : nobody) << '\n';

	const Student* s2 { findStudentById(3) };
	std::cout << "You found: " << (s2 ? s2->name : nobody) << '\n';

	return 0;
}
