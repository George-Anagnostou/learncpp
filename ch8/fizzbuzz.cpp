#include <iostream>

void fizzbuzz(int x)
{
    for (int i = 1; i <= x; ++i)
    {
        if (i % 7 == 0)
        {
            std::cout << "pop\n";
        }
        else if (i % 5 == 0 && i % 3 == 0)
        {
            std::cout << "fizzbuzz\n";
        }
        else if (i % 5 == 0)
        {
            std::cout << "buzz\n";
        }
        else if (i % 3 == 0)
        {
            std::cout << "fizz\n";
        }
        else
        {
            std::cout << i << '\n';
        }
    }
}

void fizzbuzz2(int x)
{
    for (int i = 1; i <= x; ++i)
    {
        if (i % 7 == 0 || i % 5 == 0 || i % 3 == 0)
        {
            if (i % 5 == 0)
            {
                std::cout << "buzz";
            }
            if (i % 3 == 0)
            {
                std::cout << "fizz";
            }
            if (i % 7 == 0)
            {
                std::cout << "pop";
            }
        }
        else
        {
            std::cout << i;
        }
        std::cout << '\n';
    }
}

int main()
{
    // fizzbuzz(150);
    fizzbuzz2(150);

    return 0;
}