#include <iostream>
#include <cstdint>

std::int64_t pow(int base, int exponent)
{
    std::int64_t total { 1 };

    for (int i = 0; i < exponent; ++i)
    {
        total *= base;
    }
    
    return total;
}

int main()
{
    std::cout << pow(10, 3) << '\n';
    
    return 0;
}