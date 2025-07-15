// Direction

#ifndef DIRECTION_H
#define DIRECTION_H

#include <cassert>
#include <iostream>
#include "Random.h"

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

#endif // DIRECTION_H
