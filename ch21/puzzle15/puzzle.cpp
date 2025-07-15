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

struct Point {
	int x {};
	int y {};

	Point getAdjacentPoint(Direction d) const {
		switch (d.getType()) {
		case Direction::up: 	return Point { x, y - 1 };
		case Direction::down: 	return Point { x, y + 1 };
		case Direction::left: 	return Point { x - 1, y };
		case Direction::right: 	return Point { x + 1, y };
		default: 		break;
		}

		assert(0 && "Unsupported direction was passed!");
		return *this;
	}

	friend bool operator==(const Point& p1, const Point& p2) {
		return p1.x == p2.x && p1.y == p2.y;
	}

	friend bool operator!=(const Point& p1, const Point& p2) {
		return !(p1 == p2);
	}
};

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
	friend bool operator==(const Tile& t1, const Tile& t2);
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

bool operator==(const Tile& t1, const Tile& t2) {
	if (t1.getNum() == t2.getNum()) {
		return true;
	}
	return false;
}

bool operator!=(const Tile& t1, const Tile& t2) {
	return !(t1 == t2);
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

	bool isValidMove(const Point& p) {
		return (p.x >= 0 && p.x < s_size)
		    && (p.y >= 0 && p.y < s_size);
	}

	Point findEmptyTile() const {
		for (int y = 0; y < s_size; ++y) {
			for (int x = 0; x < s_size; ++x) {
				if (m_tiles[y][x].isEmpty()) {
					return Point { x, y };
				}
			}
		}

		assert(0 && "There is no empty tile in the board!");
		return Point { -1, -1 };
	}

	void swapTiles(Point p1, Point p2) {
		std::swap(m_tiles[p1.y][p1.x], m_tiles[p2.y][p2.x]);
	}

	bool moveTile(Direction d) {
		Point emptyTile { findEmptyTile() };
		Point adjacentTile { emptyTile.getAdjacentPoint(d) };
		if (!isValidMove(adjacentTile)) {
			return false;
		}
		swapTiles(emptyTile, adjacentTile);
		return true;
	}

	void randomize() {
		for (int i = 0; i < 1000; ++i) {
			if (!moveTile(Direction::getRandomDirection())) {
				continue;
			}
		}
	}

	bool playerWon() const {
		static Board s_solved {};
		if (*this == s_solved) {
			return true;
		}
		return false;
	}

	friend std::ostream& operator<<(std::ostream& out, const Board& board);
	friend bool operator==(const Board& b1, const Board& b2);
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

bool operator==(const Board& b1, const Board& b2) {
	assert(b1.s_size == b2.s_size && "Boards sizes are incompatible!");
	for (int y = 0; y < b1.s_size; ++y) {
		for (int x = 0; x < b1.s_size; ++x) {
			if (b1.m_tiles[y][x] != b2.m_tiles[y][x]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	Board board {};
	board.randomize();
	std::cout << board;

	while (true) {
		char input { UserInput::getCommandFromUser() };
		std::cout << "Valid command: " << input << '\n';
		if (input == 'q') {
			std::cout << "\nBye!\n\n";
			return 0;
		}

		Direction d { UserInput::charToDirection(input) };
		if (board.moveTile(d)) {
			std::cout << board;
		}

		if (board.playerWon()) {
			std::cout << "\n\nYou won!\n\n";
			return 0;
		}
	}

	return 0;
}
