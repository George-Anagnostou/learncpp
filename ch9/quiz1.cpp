#include <iostream>
#include <limits>
#include "Random.h"

void welcome(int low, int high, int tries)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << low << " and " << high << ". You have " << tries << " tries to guess what it is.\n";
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            std::exit(0);
        }
        
        std::cin.clear();
        ignoreLine();
        
        return true;
    }

    return false;
}

int setParameter(std::string_view label)
{
    while (true)
    {
        std::cout << "Set " << label << " value: ";
        int x {};
        std::cin >> x;

        if (clearFailedExtraction())
        {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        ignoreLine();
        return x;
    }
}

bool validateGuess(int guess, int low, int high)
{
    if (guess < low)
    {
        std::cout << "Guess is below the lower bound. Please try again.\n";
        return false;
    }
    if (guess > high)
    {
        std::cout << "Guess is above the upper bound. Please try again.\n";
        return false;
    }
    return true;
}

int getGuess(int low, int high, int tries)
{
    while (true)
    {
        std::cout << "Guess #" << tries << ": ";
        int guess {};
        std::cin >> guess;
        
        if (clearFailedExtraction())
        {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (!validateGuess(guess, low, high))
            continue;

        ignoreLine();
        return guess;
    }
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
            std::cin.clear();
            ignoreLine();
            return true;
        case 'n':
            std::cin.clear();
            ignoreLine();
            return false;
        default:
            std::cin.clear();
            ignoreLine();
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

        int guess { getGuess(low, high, numTries) };
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