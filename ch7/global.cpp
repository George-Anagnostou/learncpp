#include <iostream>

int value { 5 };

int main()
{
    int value { 7 };
    ++value;

    --(::value);

    std::cout << "local variable value: " << value << '\n';
    std::cout << "global variable value: " << ::value << '\n';

    return 0;
}