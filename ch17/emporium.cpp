#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Potion {
	enum Type {
		healing,
		mana,
		speed,
		invisibility,
		maxPotionTypes,
	};

	constexpr std::array<int, maxPotionTypes> potionCosts {
		20, 30, 12, 50,
	};

	constexpr std::array<std::string_view, maxPotionTypes> potionNames {
		"healing",
		"mana",
		"speed",
		"invisibility",
	};

	static_assert(std::size(potionCosts) == maxPotionTypes);
	static_assert(std::size(potionNames) == maxPotionTypes);
}

void shop() {
	std::cout << "Here is our selection for today: \n";
	for (auto i = 0; i < Potion::maxPotionTypes; ++i) {
		std::cout << i << ") " 
			<< Potion::potionNames[i] 
			<< " costs " 
			<< Potion::potionCosts[i] << '\n';
	}
}

int main() {
	shop();

	return 0;
}
