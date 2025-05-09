#include "Random.h"
#include <iostream>

void welcome(int low, int high, int tries)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << low << " and " << high << ". You have " << tries << " tries to guess what it is.\n";
}

int setParameter(std::string_view label)
{
    std::cout << "Set " << label << " value: ";
    int x {};
    std::cin >> x;
    return x;
}

int getGuess(int tries)
{
    std::cout << "Guess #" << tries << ": ";
    int guess {};
    std::cin >> guess;
    return guess;
}

bool checkGuess(int answer, int guess)
{
    if (guess == answer)
    {
        std::cout << "Correct! You win!\n";
        return true;
    }
    else if (guess < answer)
    {
        std::cout << "Your guess is too low.\n";
        return false;
    }
    else
    {
        std::cout << "Your guess is too high.\n";
        return false;
    }
}

bool playAgain()
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char play {};
        std::cin >> play;
        switch (play)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            continue;
        }
    }
}

bool playGame()
{
    int low { setParameter("low") };
    int high { setParameter("high") };
    int tries { setParameter("tries") };

    welcome(low, high, tries);
    int answer { Random::get(low, high) };
    bool guessStatus { false };

    for (int numTries { 1 }; numTries <= tries; ++numTries)
    {

        int guess { getGuess(numTries) };
        guessStatus = checkGuess(answer, guess);
        if (guessStatus)
            break;
    }

    if (!guessStatus)
    {
        std::cout << "Sorry, you lose. The correct number was " << answer << '\n';
    }

    return guessStatus;
}

int main()
{
    int numTries { 1 };
    
    do
    {
        playGame();
    } while (playAgain());
    
    std::cout << "Thank you for playing.\n";
    
    return 0;
}