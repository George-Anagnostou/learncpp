// UserInput

#ifndef USERINPUT_H
#define USERINPUT_H

#include <limits>
#include <iostream>
#include "Direction.h"

namespace UserInput {
	bool isValidCommand(char ch);
	void ignoreLine();
	char getCharacter();
	char getCommandFromUser();
	Direction charToDirection(char ch);
};

#endif // USERINPUT_H
