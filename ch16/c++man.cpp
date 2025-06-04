#include "Random.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

namespace Settings {
    constexpr int maxGuesses { 6 };
}

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
    std::vector<bool> m_letterGuessed { std::vector<bool>(26) };
    int m_guessesLeft { Settings::maxGuesses };
    
    std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32) - 1); }

public:
    Session() : m_word(WordList::getRandomWord()) {}
    
    bool isLetterGuessed(char c) const { return m_letterGuessed[toIndex(c)];}
    void setLetterGuessed(char c) { m_letterGuessed[toIndex(c)] = true; }
    
    int guessesLeft() const { return m_guessesLeft; }
    void decrementGuesses() { --m_guessesLeft; }

    bool isLetterInWord(char c) const {
        for (auto ch : m_word) {
            if (ch == c ) {
                return true;
            }
        }
        return false;
    }
    
    bool won() {
        for (auto c : m_word) {
            if (!isLetterGuessed(c)) {
                return false;
            }
        }
        return true;
    }

    // returns the word in plain text
    const std::string_view getWord() const { return m_word; }
};

void draw(const Session& s) {
    std::cout << "The word: ";
    for (auto c: s.getWord()) { // step through each letter of word
        if (s.isLetterGuessed(c)) {
            std::cout << c; // if letter guessed, print it
        } else {
            std::cout << '_'; // if not guessed, print underscore
        }
    } 
    
    std::cout << "   Wrong guesses: ";
    for (int i = 0; i < s.guessesLeft(); ++i) {
        std::cout << '+'; // draw pluses for remaining guesses
    }
    
    for (char c='a'; c <= 'z'; ++c) {
        if (s.isLetterGuessed(c) && !s.isLetterInWord(c)) {
            std::cout << c; // print guessed letters
        }
    }
    
    std::cout << '\n';
}

void handleGuess(Session& s, char c) {
    s.setLetterGuessed(c);
    if (s.isLetterInWord(c)) {
        std::cout << "Yes, '" << c << "' is in the word!\n";
        return;
    }
    
    std::cout << "No, '" << c << "' is not in the word.\n";
    s.decrementGuesses();
}

char getGuess(const Session& s) {
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
        
        if (s.isLetterGuessed(c)) {
            std::cout << "You already guessed '" << c << "'. Try again.\n";
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
    
    while (session.guessesLeft() > 0 && !session.won()) {
        draw(session);

        char c { getGuess(session) };
        handleGuess(session, c);
    }
    
    draw(session);
    
    if (!session.guessesLeft()) {
        std::cout << "You lost! The word was: " << session.getWord() << '\n';
    } else {
        std::cout << "You won!\n";
    }
    
    return 0;
}