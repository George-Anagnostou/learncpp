#include <cassert>
#include <iostream>
#include <limits>
#include "Random.h"

constexpr int g_consoleLines { 25 };

class Direction {
public:
	enum Type {
		up,
		down,
		left,
		right,
		maxDirections,
	};

	Direction(Type type)
	: m_type { type }
	{}

	Type getType() const { return m_type; }

	Direction operator-() const {
		switch (m_type) {
		case Type::up: 		return Direction { Type::down };
		case Type::down: 	return Direction { Type::up };
		case Type::left: 	return Direction { Type::right };
		case Type::right: 	return Direction { Type::left };
		default:		break;
		}

		assert(0 && "Unsupported direction was passed!");
		return Direction { Type::up };
	}

	static Direction getRandomDirection() {
		Type random { static_cast<Type>(Random::get(0, Type::maxDirections - 1)) };
		return Direction { random };
	}

private:
	Type m_type {};

};

std::ostream& operator<<(std::ostream& out, const Direction& d) {
	switch (d.getType()) {
	case Direction::up: 	return (out << "up");
	case Direction::down: 	return (out << "down");
	case Direction::left: 	return (out << "left");
	case Direction::right: 	return (out << "right");
	default:		break;
	}

	assert(0 && "Unsupported direction was passed!");
	return (out << "unknown direction");
}

namespace UserInput {
	bool isValidCommand(char ch) {
		return ch == 'w'
			|| ch == 'a'
			|| ch == 's'
			|| ch == 'd'
			|| ch == 'q';
	}

	void ignoreLine() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	char getCharacter() {
		char input {};
		std::cin >> input;
		ignoreLine();
		return input;
	}

	char getCommandFromUser() {
		char input {};
		while (!isValidCommand(input)) {
			input = getCharacter();
		}
		return input;
	}

	Direction charToDirection(char ch) {
		switch (ch) {
		case 'w': return Direction { Direction::up };
		case 's': return Direction { Direction::down };
		case 'a': return Direction { Direction::left };
		case 'd': return Direction { Direction::right };
		}

		assert(0 && "Unsupported direction was passed!");
		return Direction { Direction::up };
	}
};

class Tile {
private:
	int m_value { 0 };

public:
	Tile() = default;
	explicit Tile(int value=0)
	: m_value { value }
	{
	}

	bool isEmpty() const { return m_value == 0; }

	int getNum() const { return m_value; }

	friend std::ostream& operator<<(std::ostream& out, const Tile& t);
};

std::ostream& operator<<(std::ostream& out, const Tile& t) {
	if (t.getNum() > 9) {
		out << " " << t.getNum() << " ";
	} else if (t.getNum() > 0) {
		out << "  " << t.getNum() << " ";
	} else if (t.getNum() == 0) {
		out << "   ";
	}

	return out;
}

class Board {
private:
	static constexpr int s_size { 4 };
	Tile m_tiles[s_size][s_size] {
		Tile {1}, Tile {2}, Tile {3}, Tile {4},
		Tile {5}, Tile {6}, Tile {7}, Tile {8},
		Tile {9}, Tile {10}, Tile {11}, Tile {12},
		Tile {13}, Tile {14}, Tile {15}, Tile {0}
	};

public:
	Board() = default;

	friend std::ostream& operator<<(std::ostream& out, const Board& board);
};

std::ostream& operator<<(std::ostream& out, const Board& board) {
	for (int i = 0; i < g_consoleLines; ++i) {
		out << '\n';
	}

	for (int y = 0; y < board.s_size; ++y) {
		for (int x = 0; x < board.s_size; ++x) {
			out << board.m_tiles[y][x];
		}
		out << '\n';
	}
	return out;
}

int main()
{
	// step 2
	Tile tile1{ 10 };
	Tile tile2{ 8 };
	Tile tile3{ 0 }; // the missing tile
	Tile tile4{ 1 };

	std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
	std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

	std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';
	std::cout << "Tile 2 has number: " << tile2.getNum() << "\nTile 4 has number: " << tile4.getNum() << '\n';

	
	// step 3
	Board board {};
	std::cout << board;

	// step 5
	std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
	std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
	std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
	std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';

	// step 4
	while (true) {
		char input { UserInput::getCommandFromUser() };
		std::cout << "Valid command: " << input << '\n';
		if (input == 'q') {
			std::cout << "\nBye!\n\n";
			return 0;
		}
	}

	return 0;
}
