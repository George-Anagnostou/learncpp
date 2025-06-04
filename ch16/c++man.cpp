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

void welcome() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of pluses.\n";
    std::cout << '\n';
}

int main() {
    welcome();
    
    std::cout << "The word is: " << WordList::getRandomWord() << "\n";

    return 0;
}