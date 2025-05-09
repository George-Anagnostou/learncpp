#include <iostream>

int main()
{
    char character { 'a' };
    while (character <= 'z')
    {
        std::cout << character << " | " << static_cast<int>(character) << '\n';
        ++character;
    }
    
    return 0;
}