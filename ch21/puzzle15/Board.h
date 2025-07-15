// Board

#ifndef BOARD_H
#define BOARD_H

#include "Point.h"
#include "Tile.h"

constexpr int g_consoleLines { 25 };

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

#endif // BOARD_H
