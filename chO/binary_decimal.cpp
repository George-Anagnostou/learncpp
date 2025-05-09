#include <iostream>

int getInput()
{
    std::cout << "Enter an integer between 0 and 255: ";
    int x {};
    std::cin >> x;

    return x;
}

int printBit2(int x, int pow)
{
    if (x >= pow) {
        std::cout << '1';
        return x - pow;
    } else {
        std::cout << '0';
        return x;
    }
}

void printBits2(int x)
{
    x = printBit2(x, 128);
    x = printBit2(x, 64);
    x = printBit2(x, 32);
    x = printBit2(x, 16);
    
    std::cout << ' ';

    x = printBit2(x, 8);
    x = printBit2(x, 4);
    x = printBit2(x, 2);
    x = printBit2(x, 1);
    
    std::cout << '\n';
}

void printBit3(int x, int pow)
{
    std::cout << ((x / pow) % 2);
}

void printBits3(int x)
{
    printBit3(x, 128);
    printBit3(x, 64);
    printBit3(x, 32);
    printBit3(x, 16);
    
    std::cout << ' ';

    printBit3(x, 8);
    printBit3(x, 4);
    printBit3(x, 2);
    printBit3(x, 1);
    
    std::cout << '\n';
}

int main()
{
    int input { getInput() };
    std::cout << "Method 2: \t";
    printBits2(input);

    std::cout << "Method 3: \t";
    printBits3(input);

    return 0;
}