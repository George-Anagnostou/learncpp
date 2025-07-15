// Tile

#ifndef TILE_H
#define TILE_H

#include <iostream>

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
	friend bool operator!=(const Tile& t1, const Tile& t2);
};

#endif // TILE_H
