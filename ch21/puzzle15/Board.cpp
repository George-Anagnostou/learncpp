#include "Board.h"
#include "Tile.h"

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

