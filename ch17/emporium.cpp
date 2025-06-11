#include "Random.h"
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

class Player {
private:
	static constexpr int s_minStartingGold { 80 };
	static constexpr int s_maxStartingGold { 120 };

	std::string m_name {};
	std::array<int, Potion::maxPotionTypes> m_inventory {};
	int m_gold {};

public:
	explicit Player(std::string_view name)
		: m_name { name }
		, m_gold { Random::get(s_minStartingGold, s_maxStartingGold) } 
	{
		std::cout << "Hello, " << m_name << ", you have " << m_gold << " gold.\n\n";
	}

	int gold() const { return m_gold; };
	int inventory(Potion::Type p) const { return m_inventory[p]; }
};

void shop() {
	std::cout << "Here is our selection for today: \n";
	for (auto i = 0; i < Potion::maxPotionTypes; ++i) {
		std::cout << i << ") " 
			<< Potion::potionNames[i] 
			<< " costs " 
			<< Potion::potionCosts[i] << '\n';
	}

	std::cout << '\n';
}

int main() {
	std::cout << "Welcome to Roscoe's potion emporium!\n\n";

	std::cout << "Enter your name: ";
	std::string name {};
	std::getline(std::cin >> std::ws, name);

	Player player { name };
	shop();

	std::cout << "Thanks for shopping at Roscoe's potion emporium!\n\n";

	return 0;
}
