#include <array>
#include <iostream>

constexpr int g_consoleLines { 25 };

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

	return 0;
}
