#include "Tile.h"

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

