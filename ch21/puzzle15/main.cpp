#include <cassert>
#include <iostream>
#include "Board.h"
#include "UserInput.h"

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
