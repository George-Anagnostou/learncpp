#include <iostream>
#include "Direction.h"

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

