#include "Random.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

namespace WordList {
    const std::vector<std::string_view> words = {
        "mystery", "broccoli", "account", "almost", "spaghetti",
        "opinion", "beautiful", "distance", "luggage"
    };
    
    const std::string_view getRandomWord() {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
}

class Session {
private:
    std::string m_word {};

public:
    Session() : m_word(WordList::getRandomWord()) {}

    // returns the word in plain text
    const std::string_view getWord() const { return m_word; }
};

void draw(const Session& s) {
    std::cout << "The word: ";
    for ([[maybe_unused]] auto c: s.getWord()) { // step through each letter of word
        std::cout << '_';
    } 
    
    std::cout << '\n';
}

char getGuess() {
    while(true) {
        std::cout << "Enter your next letter: ";

        char c{};
        std::cin >> c;

        // try again if bad input
        if (!std::cin) {
            // fix it
            std::cin.clear();
            std::cout << "That wasn't a valid input. Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        // clear extraneous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // if invalid character, try again
        if (c < 'a' | c > 'z') {
            std::cout << "That wasn't a valid input. Try again.\n";
            continue;
        }
        
        return c;
    }
}

void welcome() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of pluses.\n";
    std::cout << '\n';
}

int main() {
    welcome();
    
    Session session {};
    draw(session);
    char c { getGuess() };
    std::cout << "You guessed: " << c << '\n';
    
    return 0;
}