#include <algorithm> // for std::shuffle
#include <array>
#include <cassert>
#include <iostream>
#include "Random.h"

namespace Settings {
	constexpr int MAXVALUE { 21 };
	constexpr int MAXDEALER { 17 };
}

enum class EndStates {
	player_wins,
	dealer_wins,
	tie,
};

struct Card {
	enum Rank {
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,

		max_ranks,
	};

	enum Suit {
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,

		max_suits,
	};

	Rank rank{};
	Suit suit{};

	static constexpr std::array allRanks { rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };

	static constexpr std::array allSuits { suit_club, suit_diamond, suit_heart, suit_spade };

	friend std::ostream& operator<<(std::ostream& out, const Card& card) {
		static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
		static constexpr std::array suits { 'C', 'D', 'H', 'S' };

		out << ranks[card.rank] << suits[card.suit];
		return out;
	}

	int value() const {
		static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
		return rankValues[rank];
	}
};

class Deck {
private:
	std::array<Card, 52> m_cards {};
	std::size_t m_nextCardIndex { 0 };

public:
	Deck() {
		std::size_t count { 0 };
		for (auto suit : Card::allSuits) {
			for (auto rank : Card::allRanks) {
				m_cards[count++] = Card { rank, suit };
			}
		}
	}

	Card dealCard() {
		assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");

		return m_cards[m_nextCardIndex++];
	}

	void shuffle() {
		std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
		m_nextCardIndex = 0;
	}
};

struct Player {
	int score { 0 };
	int numAces { 0 };

	Card drawCard(Deck& deck) {
		Card card { deck.dealCard() };
		score += card.value();

		if (card.rank == Card::rank_ace) {
			++numAces;
		}

		if (score > Settings::MAXVALUE && numAces > 0) {
			--numAces;
			score -= 10;
		}

		return card;
	}
};

// returns true if dealer successfully finishes turns
// returns false if dealer busts
bool dealerTurn(Player dealer, Deck deck) {
	while (dealer.score < Settings::MAXDEALER) {
		Card card { dealer.drawCard(deck) };
		std::cout << "The dealer flips a " << card << ". ";
		std::cout << "They now have: " << dealer.score << '\n';
	}

	if (dealer.score > Settings::MAXVALUE) {
		return false;
	}

	return true;
}

bool handleInput() {
	while (true) {
		std::cout << "(h) to hit, or (s) to stand: ";
		char move {};
		std::cin >> move;
		switch(move) {
		case 'h':
			return true;
		case 's':
			return false;
		default:
			std::cout << "Invalid input. Try again.\n";
			continue;
		}
	}
}

// returns true if player successfully finishes turn
// returns false if player busts
bool playerTurn(Player player, Deck deck) {
	bool move { handleInput() };
	while (move) {
		Card card { player.drawCard(deck) };
		std::cout << "You were dealt: " << card << ". ";
		std::cout << "You now have " << player.score << '\n';

		if (player.score > Settings::MAXVALUE) {
			return false;
		}

		move = handleInput();
	}
	return true;
}

EndStates playBlackJack() {
	Deck deck {};
	deck.shuffle();

	Player dealer {};
	Player player {};

	Card dealerCard { dealer.drawCard(deck) };
	Card playerCard { player.drawCard(deck) };

	std::cout << "The dealer is showing: " << dealerCard << " (" << dealer.score << ")\n";
	std::cout << "You are showing: " << playerCard << " (" << player.score << ")\n";

	if (!playerTurn(player, deck)) {
		std::cout << "You bust!\n";
		return EndStates::dealer_wins;
	}

	if (!dealerTurn(dealer, deck)) {
		std::cout << "The dealer busts!\n";
		return EndStates::player_wins;
	}

	if (dealer.score > player.score) {
		std::cout << "The dealer's " << dealer.score << " beats your " << player.score << "!\n";
		return EndStates::dealer_wins;
	}

	if (dealer.score == player.score) {
		std::cout << "You and the dealer have the same score!\n";
		return EndStates::tie;
	}

	return EndStates::player_wins;
}

int main() {
	EndStates status { playBlackJack() };

	switch (status) {
	case EndStates::player_wins:
		std::cout << "You win!\n";
		break;
	case EndStates::dealer_wins:
		std::cout << "You lose!\n";
		break;
	case EndStates::tie:
		std::cout << "It's a tie!\n";
		break;
	default:
		std::cout << "Error handling winner.\n";
		break;
	}

	return 0;
}
