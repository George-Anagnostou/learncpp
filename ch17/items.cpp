#include <array>
#include <iostream>
#include <string_view>

struct Item {
	std::string_view name {};
	int gold {};
};

template <std::size_t N>
void printItems(const std::array<Item, N>& arr) {
	for (const auto& elm : arr) {
		std::cout << "A " << elm.name << " costs " << elm.gold << " gold.\n";
	}
}

int main() {
	std::array items {
		Item { "sword", 5 },
		Item { "dagger", 3 },
		Item { "club", 2 },
		Item { "spear", 7 },
	};
	printItems(items);

	std::array<Item, 4> items2 {{
		{ "sword", 5 },
		{ "dagger", 3 },
		{ "club", 2 },
		{ "spear", 7 },
	}};
	printItems(items2);

	return 0;
}
