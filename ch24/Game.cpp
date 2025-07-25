#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include "Random.h"

class Potion {
public:
	enum Type {
		health,
		strength,
		poison,
		max_type,
	};

	enum Size {
		small,
		medium,
		large,
		max_size,
	};

private:
	Type m_type {};
	Size m_size {};

public:
	Potion(Type type, Size size)
	: m_type { type }
	, m_size { size }
	{}

	Type getType() const { return m_type; }
	Size getSize() const { return m_size; }

	static std::string_view getPotionTypeName(Type type) {
		static constexpr std::string_view names[] {
			"Health",
			"Strength",
			"Poison",
		};

		return names[type];
	}

	static std::string_view getPotionSizeName(Size size) {
		static constexpr std::string_view names[] {
			"Small",
			"Medium",
			"Large",
		};

		return names[size];
	}

	std::string getName() const {
		std::stringstream result {};
		result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());
		return result.str();
	}

	static Potion getRandomPotion() {
		return Potion {
			static_cast<Type>(Random::get(0, max_type - 1)),
			static_cast<Size>(Random::get(0, max_size - 1))
		};
	}
};

class Creature {
protected:
	std::string m_name {};
	char m_symbol {};
	int m_health {};
	int m_dpa {};
	int m_gold {};

public:
	Creature(std::string_view name, char symbol, int health, int dpa, int gold)
	: m_name { name }
	, m_symbol { symbol }
	, m_health { health }
	, m_dpa { dpa }
	, m_gold { gold }
	{}

	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_health; }
	int getDPA() const { return m_dpa; }
	int getGold() const { return m_gold; }

	void reduceHealth(int damage) { m_health -= damage; }

	bool isDead() const { return m_health <= 0; }

	void addGold(int gold) { m_gold += gold; }
};

class Player : public Creature {
private:
	int m_level {};

public:
	Player(std::string name)
	: Creature{ name, '@', 10, 1, 0 }
	, m_level { 1 }
	{}

	void levelUp() { 
		++m_level; 
		++m_dpa;
	}
	int getLevel() const { return m_level; }
	bool hasWon() const { return m_level >= 20; }
	void drinkPotion(const Potion& potion) {
		switch (potion.getType()) {
		case Potion::health:
			m_health += ((potion.getSize() == Potion::large ? 5 : 2));
			break;
		case Potion::strength:
			m_dpa += 1;
			break;
		case Potion::poison:
			m_health -= 1;
			break;
		default:
			std::cout << "Invalid state.\n";
			break;
		}
	}
};

std::ostream& operator<<(std::ostream& out, const Player& player) {
	out << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";
	return out;
}

class Monster : public Creature {
public:
	enum Type {
		dragon,
		orc,
		slime,
		max_types,
	};
	
private:
	inline static Creature monsterData[] {
		Creature { "dragon", 'D', 20, 4, 100 },
		Creature { "orc" , 'o', 4, 2, 25 },
		Creature { "slime", 's', 1, 1, 10 },
	};

	static_assert(std::size(monsterData) == max_types);

public:
	Monster(Type t)
	: Creature{ monsterData[t] }
	{}

	static Monster getRandomMonster() {
		int num { static_cast<Type>(Random::get(0, max_types-1)) };
		return Monster { static_cast<Type>(num) };
	}
};

std::string getUserName() {
	std::cout << "Enter your name: ";
	std::string name {};
	std::cin >> name;
	return name;
}

void welcome(std::string_view name) {
	std::cout << "Welcome, " << name << '\n';
}

char runOrFight() {
	std::cout << "(r)un or (f)ight: ";
	char action {};
	std::cin >> action;
	return action;
}

void attackMonster(Player& player, Monster& monster) {
	if (player.isDead()) {
		return;
	}
	std::cout << "You hit the " << monster.getName() << " for " << player.getDPA() << " damage.\n";
	monster.reduceHealth(player.getDPA());
	if (monster.isDead()) {
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
	}
}

void attackPlayer(const Monster& monster, Player& player) {
	if (monster.isDead()) {
		return;
	}
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDPA() << " damage.\n";
	player.reduceHealth(monster.getDPA());
}

char getChoice() {
	std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
	char choice {};
	std::cin >> choice;
	return choice;
}

void findPotion(Player& player) {
	auto potion { Potion::getRandomPotion() };
	char choice { getChoice() };
	if (choice == 'y') {
		player.drinkPotion(potion);
		std::cout << "You drank a " << potion.getName() << ".\n";
	}
}

void fightMonster(Player& player) {
	Monster monster { Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
	while (!monster.isDead() && !player.isDead()) {
		char action { runOrFight() };
		if (action == 'f') {
			attackMonster(player, monster);
			attackPlayer(monster, player);
			if (monster.isDead()) {
				constexpr int potionChance { 30 };
				if (Random::get(1, 100) <= potionChance) {
					findPotion(player);
				}
			}
		}
		if (action == 'r') {
			// 50% chance of fleeing successfully
			if (Random::get(1, 2) == 1) {
				std::cout << "You fled successfully.\n";
				return;
			} else {
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, player);
			}
		}
	}
}

int main() {
	Player player { getUserName() };
	welcome(player.getName());

	while (!player.isDead() && !player.hasWon()) {
		fightMonster(player);
	}

	if (player.isDead()) {
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	} else {
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}

	return 0;
}
