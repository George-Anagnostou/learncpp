#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include "Random.h"

namespace Potion {
	enum Type {
		healing,
		mana,
		speed,
		invisibility,
		maxPotionTypes,
	};

	constexpr std::array types { healing, mana, speed, invisibility };

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

	bool buy(Potion::Type type) {
		if (m_gold < Potion::potionCosts[type]) {
			return false;
		}

		m_gold -= Potion::potionCosts[type];
		++m_inventory[type];
		return true;
	}
};

void printInventory(Player& player) {
	std::cout << "Your inventory contains: \n";
	for (auto p : Potion::types) {
		if (player.inventory(p) > 0) {
			std::cout << player.inventory(p) << "x potion of " << Potion::potionNames[p] << '\n';
		}
	}
	std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}

void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c) {
	return c - '0';
}

Potion::Type whichPotion() {
	std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
	char input{};
	while (true) {
		std::cin >> input;
		if (!std::cin) {
			std::cin.clear();
			ignoreLine();
			continue;
		}

		if (!std::cin.eof() && std::cin.peek() != '\n') {
			std::cout << "I didn't understand what you said. Try again: ";
			ignoreLine();
			continue;
		}

		if (input == 'q') {
			return Potion::maxPotionTypes;
		}

		int val { charNumToInt(input) };
		if (val >= 0 && val < Potion::maxPotionTypes) {
			return static_cast<Potion::Type>(val);
		}

		std::cout << "I didn't understand what you said. Try again: ";
		ignoreLine();
	}
}

void shop(Player &player) {
	while (true) {
		std::cout << "Here is our selection for today: \n";
		for (auto i = 0; i < Potion::maxPotionTypes; ++i) {
			std::cout << i << ") " 
				<< Potion::potionNames[i] 
				<< " costs " 
				<< Potion::potionCosts[i] << '\n';
		}

		Potion::Type which { whichPotion() };
		if (which == Potion::maxPotionTypes) {
			return;
		}

		bool success { player.buy(which) };
		if (!success) {
			std::cout << "You can't afford that.\n\n";
		} else {
			std::cout << "You purchased a potion of " << Potion::potionNames[which]
				  << ". You have " << player.gold() << " gold left.\n\n";
		}

		std::cout << '\n';
	}
}

int main() {
	std::cout << "Welcome to Roscoe's potion emporium!\n\n";

	std::cout << "Enter your name: ";
	std::string name {};
	std::getline(std::cin >> std::ws, name);

	Player player { name };
	shop(player);

	printInventory(player);

	std::cout << "Thanks for shopping at Roscoe's potion emporium!\n\n";

	return 0;
}
